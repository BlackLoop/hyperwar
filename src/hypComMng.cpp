#include "hypComMng.h"

using namespace std;

ofVec3f lastPadCurseur;
ofVec3f padCurseur;

hypComMng::hypComMng()
{

}

hypComMng::~hypComMng()
{
    padSerial.close();
    unoSerial.close();
}

void hypComMng::Setup() {

    padSerial.setup("/dev/ttyACM0", 115200);
    unoSerial.setup("/dev/ttyACM1", 115200);
    ofSleepMillis(600); // Let it cool down, dude...
    state = INIT; // Initilialize state

}


void hypComMng::Update() {

    if ((state == INIT) && (ofGetElapsedTimef() > 5.f)) {
                printf("INIT done... Sending V to start receiving values !\n"); // Debug
                padSerial.writeByte('V');
                state = WAITING;
    }
    while (padSerial.available()) {

        uint8_t byte = padSerial.readByte();


        if (state == RECEIVING) {
            trame[byteCount] = byte; // 15 bytes as follow : XXXX|YYYY|ZZZZ representing cursor X, Y, Z
            byteCount += 1;
            if (byteCount == 16) {
                trame[15] = 0; // Null byte at end
                //printf("voici : %s.\n", trame); // Debug
                processCoordinates();
                byteCount = 0; // reset counter
                state = WAITING; // reset state
            }
        }
        if ( (state == WAITING) && (byte == 'V') ) {
            //printf("Début de trame !\n"); // Debug
            state = RECEIVING; // toggle state for receiving
        }
    }

    while (unoSerial.available()) {

        uint8_t byte = unoSerial.readByte();

        if (byte == 'A') {
            ofSendMessage("hypComMng::A");
        }
        if (byte == 'B') {
            ofSendMessage("hypComMng::B");
        }

    }

}

ofVec3f lowPass(ofVec3f current, ofVec3f last, double level ){
    // Basic linear lowpass filter x(t) = level * x(t-1) + level * x(t)

    ofVec3f result;
    result.x = level * last.x + (1 - level) * current.x;
    result.y = level * last.y + (1 - level) * current.y;
    result.z = level * last.z + (1 - level) * current.z;
    return result;

}

ofVec2f scrollVector (ofVec2f point, ofVec2f center) {

    ofVec2f result = point - center; // substract to center on (0,0)
    result /= center; // normalize around center (half Width / Height)
    result.y *= -1; // Invert Y axis
    return result;

}


void hypComMng::processCoordinates(){
    // 0077|0038|0  2  2  3| Example UART data formatted as follows : XXXX|YYYY|ZZZZ
    // 0123 5678 10 11 12 13 Indexes of digits, XXXX is 3 2 1, LSB
    padCurseur.x = trame[3] - 48 + (trame[2] - 48) * 10 + (trame[1] - 48) * 100;
    padCurseur.y = trame[8] - 48 + (trame[7] - 48) * 10 + (trame[6] - 48) * 100;
    padCurseur.z = trame[13] - 48 + (trame[12] - 48) * 10 + (trame[11] - 48) * 100;

    ofVec3f filteredCoords = lowPass(ofVec3f(padCurseur.x, padCurseur.y, padCurseur.z), lastPadCurseur, 0.97);
    ofVec3f coordsNorm(filteredCoords.x , 100.f - filteredCoords.y, padCurseur.z/300.f); // XXX Fix me, very ugly and useless! lol... Fergus is writing crappy code !
    ofVec2f center(50, 50);

    ofVec2f scrollSpeed(scrollVector(coordsNorm, center));
    printf("%f - %f\n", scrollSpeed.x, scrollSpeed.y); // Debug

    //hypCameraModel::Instance()->SetMoveVector(scrollSpeed);
    //printf(" - pack : X : %f | Y : %f | Z : %f\n", padCurseur.x, padCurseur.y, padCurseur.z); // Debug

}

