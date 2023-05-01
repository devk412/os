#include<stdio.h>

struct process {
    int id;
    int burst;
    int waiting;
    int turnaround;
    int priority;
};
void sort(struct process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void display(struct process p[], int n) {
    printf("\n\nPriority\tID\tBurst\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\n", p[i].priority, p[i].id, p[i].burst);
    }
}

int main() {
    int n, ttl_tat = 0, ttl_wt = 0;
    float avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Enter priority of process %d:", i + 1);
        scanf("%d", &p[i].priority);
        p[i].id = i + 1;
    }

    sort(p, n);
    display(p, n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p[i].waiting = 0;
            p[i].turnaround = p[i].burst;
        } else {
            p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
            p[i].turnaround = p[i].waiting + p[i].burst;
        }
        ttl_tat += p[i].turnaround;
        ttl_wt += p[i].waiting;

        printf("Waiting Time for process %d:%d\t", p[i].id, p[i].waiting);
        printf("Turnaround Time for process %d:%d\n", p[i].id, p[i].turnaround);
    }

    avg_tat = (float) ttl_tat / n;
    avg_wt = (float) ttl_wt / n;
    printf("Average Wait time: %.2f\tAverage Turnaround Time: %.2f", avg_tat, avg_wt);
    return 0;
}
