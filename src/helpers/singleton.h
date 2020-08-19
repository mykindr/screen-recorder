#ifndef RAY_HELPER_SINGLETON_H
#define RAY_HELPER_SINGLETON_H

#include <memory>
#include <mutex>

namespace ray {
	namespace helper {

		template<typename T>
		class Singleton
		{
		public:
			static T& getInstance() {
				static std::mutex mutex_;

				if (instance_.get() == nullptr) {

					std::lock_guard<std::mutex> lock(mutex_);

					if (instance_.get() == nullptr)
						instance_.reset(new T());

				}

				return *instance_;
			}

		protected:
			Singleton() {}
			virtual ~Singleton() {}

		private:
			Singleton(const Singleton&) = delete;
			Singleton& operator=(const Singleton&) = delete;

			static std::auto_ptr<T> instance_;
		};

		template <typename T>
		std::auto_ptr<T> Singleton<T>::instance_;

	} // namespace helper
} // namespace ray

#endif // RAY_HELPER_SINGLETON_H