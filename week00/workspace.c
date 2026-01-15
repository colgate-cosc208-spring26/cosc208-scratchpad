#include <stdio.h>


int main() {
        int days = 7;
        days *= 2;
        int hours = days * 24;
        int minutes = hours * 60;
        printf("%d days %d hours %d minutes in a week\n", days, hours, minutes);
        return 0;
}
