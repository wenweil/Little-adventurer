#include <thread>

namespace melodramatic{
    class ticker{
        public:
            static ticker* getInstance();
            void startTicking(int timePerTick);
            void startTicking();
            void stopTicking();
        private:
            ticker() : one() {};
            void tick();
            static ticker* instance;
            std::thread one;
            bool ticking = false;
            int tickSpeed = 100;
    };
}