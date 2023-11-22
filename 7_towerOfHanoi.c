#include <stdio.h>

// Function to simulate the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Validate the input
    if (n <= 0) {
        printf("Invalid input. Number of disks should be greater than 0.\n");
        return 1;
    }

    // Call the Tower of Hanoi function
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
