#pragma once

namespace cc {
	
	class UserDefault : noncopyable
	{
	public:
		template <class T>
		void runReader(T& nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			JsonReader jsonReader_;
			if (jsonReader_.loadFile(storagePath_.c_str())) {
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue.headSerialize(ioReader_, nName);
			}
		}
		
		template <class T>
		void runReader(T * nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			JsonReader jsonReader_;
			if (jsonReader_.loadFile(storagePath_.c_str())) {
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			}
		}
		
		template <class T>
		void runReader(SPTR<T>& nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			JsonReader jsonReader_;
			if (jsonReader_.loadFile(storagePath_.c_str())) {
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			}
		}
		
		template <class T>
		void runSave(T& nValue, const char * nUrl, const char * nName)
		{
			JsonWriter jsonWriter_;
			IoWriter<JsonWriter> ioWriter_(jsonWriter_);
			ioWriter_.selectStream(nName);
			nValue.headSerialize(ioWriter_, nName);
			
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			jsonWriter_.saveFile(storagePath_.c_str());
		}
		
		template <class T>
		void runSave(T * nValue, const char * nUrl, const char * nName)
		{
			JsonWriter jsonWriter_;
			IoWriter<JsonWriter> ioWriter_(jsonWriter_);
			ioWriter_.selectStream(nName);
			nValue->headSerialize(ioWriter_, nName);
			
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			jsonWriter_.saveFile(storagePath_.c_str());
		}
		
		template <class T>
		void runSave(SPTR<T>& nValue, const char * nUrl, const char * nName)
		{
			JsonWriter jsonWriter_;
			IoWriter<JsonWriter> ioWriter_(jsonWriter_);
			ioWriter_.selectStream(nName);
			nValue->headSerialize(ioWriter_, nName);
			
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string storagePath_ = workDirectory_.storagePath(nUrl);
			jsonWriter_.saveFile(storagePath_.c_str());
		}
		
		static UserDefault& instance();
		
		UserDefault();
		~UserDefault();
		
	private:
		static UserDefault mUserDefault;
	};
	
}
