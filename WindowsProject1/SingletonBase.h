#pragma once
//템플릿 이용한 싱글톤 패턴

template<typename T> //template <class T>
class SingletonBase
{
	//생성자 숨기기
protected:
	static T* Instance;

	SingletonBase() {};
	~SingletonBase() {};

public:
	static T* GetInstance();		//싱글턴 인스턴스 가져오기
	void ReleaseInstance();			//싱글턴 인스턴스 해제하기
};

template<typename T>
T* SingletonBase<T>::Instance = NULL;

//template이라 컴파일과정에서 정해지므로 inline이 좋음
template<typename T>
inline T* SingletonBase<T>::GetInstance()
{
	//없으면 생성
	if (!Instance)
		Instance = new T;
	
	return Instance;
}

template<typename T>
inline void SingletonBase<T>::ReleaseInstance()
{
	if (Instance) {
		delete Instance;
		Instance = NULL;
	}
}
