#pragma once

class Timer {
    public:
        Timer();

        void start();
        void stop();

        void pause();
        void resume();

        /**
         * Gets the timer's time
         */
        Uint32 getTicks();

        bool isStarted();
        bool isPaused();

    private:
        Uint32 startTicks;
        Uint32 pausedTicks;
        
        bool started;
        bool paused;
};