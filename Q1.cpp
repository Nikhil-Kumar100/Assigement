#include <iostream>
using namespace std;

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
public:
    // Constructor
    Process(int p, int a, int b) {
        pid = p;
        arrival_time = a;
        burst_time = b;
        completion_time = 0;
        turn_around_time = 0;
        waiting_time = 0;
        response_time = 0;
    }

    // Setter functions
    void set_completion_time(int t) { completion_time = t; }
    void set_turn_around_time() { turn_around_time = completion_time - arrival_time; }
    void set_waiting_time() { waiting_time = turn_around_time - burst_time; }
    void set_response_time() { response_time = completion_time - arrival_time; }

    // Getter functions
    int get_pid() { return pid; }
    int get_arrival_time() { return arrival_time; }
    int get_burst_time() { return burst_time; }
    int get_completion_time() { return completion_time; }
    int get_turn_around_time() { return turn_around_time; }
    int get_waiting_time() { return waiting_time; }
    int get_response_time() { return response_time; }

    // Print function
    void print_values() {
        cout << "Process ID: " << pid << endl;
        cout << "Arrival Time: " << arrival_time << endl;
        cout << "CPU Burst Time: " << burst_time << endl;
        cout << "Completion Time: " << completion_time << endl;
        cout << "Turnaround Time: " << turn_around_time << endl;
        cout << "Waiting Time: " << waiting_time << endl;
        cout << "Response Time: " << response_time << endl;
    }
};

int main() {
    // Create a Process object with PID 1, arrival time 0, and burst time 10
    Process p1(1, 0, 10);

    // Assign values to the remaining data members once the process has completed
    p1.set_completion_time(15);
    p1.set_turn_around_time();
    p1.set_waiting_time();
    p1.set_response_time();

    // Print the values of all data members
    p1.print_values();

    return 0;
}
