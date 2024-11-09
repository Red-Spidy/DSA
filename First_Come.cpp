#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a process
struct Process {
    int id;         // Process ID
    int burstTime;  // Burst time of the process
    int arrivalTime;// Arrival time of the process
};

// Class to implement a custom Queue for Process
class ProcessQueue {
private:
    Process* queue;    // Dynamic array for storing processes
    int front, rear, capacity;

public:
    // Constructor to initialize queue with a given size
    ProcessQueue(int size) {
        queue = new Process[size];
        front = -1;
        rear = -1;
        capacity = size;
    }

    // Destructor to free dynamically allocated memory
    ~ProcessQueue() {
        delete[] queue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Function to enqueue a process in the queue
    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue process." << endl;
            return;
        }
        if (front == -1) {
            front = 0;  // Initialize front to 0 on first enqueue
        }
        queue[++rear] = p;
    }

    // Function to dequeue a process from the queue
    Process dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue process." << endl;
            exit(1);
        }
        Process p = queue[front];
        if (front == rear) {  // Reset queue when last element is dequeued
            front = rear = -1;
        } else {
            front++;
        }
        return p;
    }

    // Function to get the front process without dequeuing
    Process peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek process." << endl;
            exit(1);
        }
        return queue[front];
    }
};

// Function to simulate FCFS scheduling and calculate turnaround and waiting times
void FCFS_Scheduling(ProcessQueue &processQueue, int n) {
    vector<int> turnaroundTimes;  // To store turnaround times for each process
    vector<int> waitingTimes;     // To store waiting times for each process
    int currentTime = 0;

    // Processing each process in the queue
    while (!processQueue.isEmpty()) {
        Process currentProcess = processQueue.dequeue();

        // If process arrives after the current time, move time forward
        if (currentTime < currentProcess.arrivalTime) {
            currentTime = currentProcess.arrivalTime;
        }

        // Calculate waiting time and turnaround time
        int waitingTime = currentTime - currentProcess.arrivalTime;
        int turnaroundTime = waitingTime + currentProcess.burstTime;

        // Store the results
        waitingTimes.push_back(waitingTime);
        turnaroundTimes.push_back(turnaroundTime);

        // Update current time after process execution
        currentTime += currentProcess.burstTime;

        // Display the process details
        cout << "Process " << currentProcess.id 
             << " | Waiting Time: " << waitingTime 
             << " | Turnaround Time: " << turnaroundTime << endl;
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < waitingTimes.size(); i++) {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }
    avgWaitingTime /= waitingTimes.size();
    avgTurnaroundTime /= turnaroundTimes.size();

    // Display average times
    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main() {
    int n;
    
    // Taking input for number of processes
    cout << "Enter number of processes: ";
    cin >> n;

    // Create a queue for 'n' processes
    ProcessQueue processQueue(n);

    // Taking input for each process and enqueue it
    for (int i = 0; i < n; ++i) {
        Process p;
        cout << "Enter arrival time and burst time for process " << i+1 << ": ";
        p.id = i + 1;
        cin >> p.arrivalTime >> p.burstTime;
        processQueue.enqueue(p);
    }

    // Simulate FCFS scheduling
    FCFS_Scheduling(processQueue, n);

    return 0;
}
