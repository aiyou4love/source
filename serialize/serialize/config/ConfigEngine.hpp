#pragma once

namespace cc {
	
	class ConfigEngine : noncopyable
	{
	public:
		template <class T>
		void runReader(T& nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string tablePath_ = workDirectory_.configPath(nUrl);
			TableReader tableReader_;
			if (tableReader_.loadFile(tablePath_.c_str())) {
				tableReader_.selectStream(nName);
				if (tableReader_.runChild(nName)) {
					IoReader<TableReader> ioReader_(tableReader_);
					nValue.headSerialize(ioReader_, nName);
				}
			}
		}
		
		template <class T>
		void runReader(T * nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string tablePath_ = workDirectory_.configPath(nUrl);
			TableReader tableReader_;
			if (tableReader_.loadFile(tablePath_.c_str())) {
				tableReader_.selectStream(nName);
				if (tableReader_.runChild(nName)) {
					IoReader<TableReader> ioReader_(tableReader_);
					nValue->headSerialize(ioReader_, nName);
				}
			}
		}
		
		template <class T>
		void runReader(SPTR<T>& nValue, const char * nUrl, const char * nName)
		{
			WorkDirectory& workDirectory_ = WorkDirectory::instance();
			string tablePath_ = workDirectory_.configPath(nUrl);
			TableReader tableReader_;
			if (tableReader_.loadFile(tablePath_.c_str())) {
				tableReader_.selectStream(nName);
				if (tableReader_.runChild(nName)) {
					IoReader<TableReader> ioReader_(tableReader_);
					nValue->headSerialize(ioReader_, nName);
				}
			}
		}
		
		static ConfigEngine& instance();
		
		ConfigEngine();
		~ConfigEngine();
		
	private:
		static ConfigEngine mConfigEngine;
	};
	
}
