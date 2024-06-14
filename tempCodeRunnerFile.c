import java.util.Scanner;

class RoundRobinScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Round Robin Scheduling Menu:");
            System.out.println("1. Enter process details");
            System.out.println("2. Run Round Robin Scheduler");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    runProcessDetailsInput(scanner);
                    break;
                case 2:
                    runRoundRobinScheduler();
                    break;
                case 3:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 3);

        scanner.close();
    }

    static int[] arrivalTime;
    static int[] burstTime;
    static int[] completionTime;
    static int[] turnaroundTime;
    static int[] waitingTime;

    static void runProcessDetailsInput(Scanner scanner) {
        System.out.print("Enter the number of processes: ");
        int n = scanner.nextInt();
        arrivalTime = new int[n];
        burstTime = new int[n];
        completionTime = new int[n];
        turnaroundTime = new int[n];
        waitingTime = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for process " + (i + 1) + ":");
            System.out.print("Arrival Time: ");
            arrivalTime[i] = scanner.nextInt();
            System.out.print("Burst Time: ");
            burstTime[i] = scanner.nextInt();
        }
    }

    static void runRoundRobinScheduler() {
        if (arrivalTime == null || burstTime == null) {
            System.out.println("Please enter process details first.");
            return;
        }

        int n = arrivalTime.length;
        int[] remainingTime = new int[n];
        int quantum;

        System.out.print("Enter the time quantum: ");
        Scanner scanner = new Scanner(System.in);
        quantum = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            remainingTime[i] = burstTime[i];
        }

        int currentTime = 0;
        while (true) {
            boolean done = true;
            for (int i = 0; i < n; i++) {
                if (remainingTime[i] > 0) {
                    done = false;
                    if (remainingTime[i] > quantum) {
                        currentTime += quantum;
                        remainingTime[i] -= quantum;
                    } else {
                        currentTime += remainingTime[i];
                        completionTime[i] = currentTime;
                        remainingTime[i] = 0;
                    }
                }
            }
            if (done) {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            turnaroundTime[i] = completionTime[i] - arrivalTime[i];
            waitingTime[i] = turnaroundTime[i] - burstTime[i];
        }

        System.out.println("\nProcess\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println((i + 1) + "\t" + arrivalTime[i] + "\t" + burstTime[i] + "\t" + completionTime[i]
                    + "\t" + turnaroundTime[i] + "\t" + waitingTime[i]);
        }
        displayGanttChart();
    }

    static void displayGanttChart() {
        System.out.println("\nGantt Chart:");
        int n = arrivalTime.length;
        for (int i = 0; i < n; i++) {
            System.out.print("| P" + (i + 1) + " ");
            System.out.print(completionTime[i] > 9 ? completionTime[i] : " " + completionTime[i] + " ");
        }
        System.out.print("|");
    }
}
