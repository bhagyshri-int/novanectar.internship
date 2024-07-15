#include <iostream>
#include <chrono>
#include <thread>

class Stopwatch
{
    private:
    std::chrono::steady_clock::time_point start_time;
    bool is_running;

public:
    Stopwatch() : is_running(false) {}

    void start()


    {
        if (!is_running)
        {
            start_time = std::chrono::steady_clock::now();
            is_running = true;
            std::cout << "Stopwatch started.\n";
        }
         else
        {
            std::cout << "Stopwatch is already running.\n";
        }
    }

    void stop()
    {
        if (is_running)
        {
            auto end_time = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
            int hours = elapsed / 3600;
            int minutes = (elapsed % 3600) / 60;
            int seconds = elapsed % 60;
            std::cout << "Elapsed time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds.\n";
            is_running = false;
        } else
        {
            std::cout << "Stopwatch is not running.\n";
        }
    }

    void reset()
    {
        is_running = false;
        std::cout << "Stopwatch reset.\n";
    }
};

int main()
{
    Stopwatch stopwatch;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (start/stop/reset/exit): ";
        std::cin >> command;

        if (command == "start")
        {
            stopwatch.start();
        } else if (command == "stop")
        {
            stopwatch.stop();
        } else if (command == "reset")
        {
            stopwatch.reset();
        } else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
