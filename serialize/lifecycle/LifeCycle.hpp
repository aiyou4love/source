#pragma once

namespace cc {
	
	class LifeCycle : noncopyable
	{
	public:
		STD_SIGNAL<void()> m_tRunLuaApi;
		void runLuaApi();
		
		STD_SIGNAL<void()> m_tLoadBegin;
		void loadBegin();
		STD_SIGNAL<void()> m_tLoading;
		void loading();
		STD_SIGNAL<void()> m_tLoadEnd;
		void loadEnd();
		
		STD_SIGNAL<void()> m_tInitBegin;
		void initBegin();
		STD_SIGNAL<void()> m_tIniting;
		void initing();
		STD_SIGNAL<void()> m_tInitEnd;
		void initEnd();
		
		STD_SIGNAL<void()> m_tStartBegin;
		void startBegin();
		STD_SIGNAL<void()> m_tStarting;
		void starting();
		STD_SIGNAL<void()> m_tStartEnd;
		void startEnd();
		
		STD_SIGNAL<void()> m_tRunBegin;
		void runBegin();
		STD_SIGNAL<void()> m_tRunning;
		void running();
		STD_SIGNAL<void()> m_tRunEnd;
		void runEnd();
		
		STD_SIGNAL<void()> m_tRunJoin;
		void runJoin();
		STD_SIGNAL<void()> m_tStopJoin;
		void stopJoin();
		
		STD_SIGNAL<void()> m_tNoticeStop;
		void noticeStop();
		STD_SIGNAL<void()> m_tNoticeStart;
		void noticeStart();
		
		STD_SIGNAL<void()> m_tStopBegin;
		void stopBegin();
		STD_SIGNAL<void()> m_tStoping;
		void stoping();
		STD_SIGNAL<void()> m_tStopEnd;
		void stopEnd();
		
		STD_SIGNAL<void()> m_tSaveBegin;
		void saveBegin();
		STD_SIGNAL<void()> m_tSaving;
		void saving();
		STD_SIGNAL<void()> m_tSaveEnd;
		void saveEnd();
		
		STD_SIGNAL<void()> m_tCloseBegin;
		void closeBegin();
		STD_SIGNAL<void()> m_tClosing;
		void closing();
		STD_SIGNAL<void()> m_tCloseEnd;
		void closeEnd();
		
		STD_SIGNAL<void()> m_tClearBegin;
		void clearBegin();
		STD_SIGNAL<void()> m_tClearing;
		void clearing();
		STD_SIGNAL<void()> m_tClearEnd;
		void clearEnd();
		
		STD_SIGNAL<void()> m_tResumeBegin;
		void resumeBegin();
		STD_SIGNAL<void()> m_tResuming;
		void resuming();
		STD_SIGNAL<void()> m_tResumeEnd;
		void resumeEnd();
		
		STD_SIGNAL<void()> m_tPauseBegin;
		void pauseBegin();
		STD_SIGNAL<void()> m_tPausing;
		void pausing();
		STD_SIGNAL<void()> m_tPauseEnd;
		void pauseEnd();
		
		bool isPause();
		
		static LifeCycle& instance();
		
		LifeCycle();
		~LifeCycle();
		
	private:
		static LifeCycle mLifeCycle;
		
		atomic<bool> mPause;
	};
	
}
