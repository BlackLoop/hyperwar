//design pattern singleton pour les assets
#pragma once
#include <assert.h>   

template <class T>
class Singleton
{
protected:
  // Constructeur/destructeur
	Singleton() {}
	~Singleton() {}

public:
  // Interface publique
  static T* Instance() 
  {
      if(!m_pInstance) m_pInstance = new T;
      assert(m_pInstance != 0);
      return m_pInstance;
  }

  static void kill() { if (m_pInstance) delete m_pInstance; }

private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
  static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance=0;

