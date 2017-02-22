#pragma once

#define INIT_SINGLETON(CLASS_NAME) CLASS_NAME* Singleton<CLASS_NAME>::mInstance = 0

template <typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		if (mInstance == 0)
		{
			mInstance = new T();
		}
		return mInstance;
	}

protected:
	Singleton()
	{
		mInstance = static_cast< T* >(this);
	}

	~Singleton(void)
	{
		mInstance = 0;
	}

private:
	static T* mInstance;
};

