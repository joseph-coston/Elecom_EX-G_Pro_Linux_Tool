/**
 * @file elecom_ex-g_pro_enhancer.c
 * @brief A program to read in the information sent to the computer from the
 * Elecom EX-G Pro wireless mouse and enable use of its additional buttons.
 * @date June 12, 2020
 * @author Joseph Coston
 */
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>

#define DEBUG 1
#define BUF_LEN 8 // DO NOT CHANGE!!!

/**
 * enumerator for more verbose button binding constants
 */
enum ID {
        LEFT = 0x10, RIGHT, MIDDLE, BACK, FORWARD, THUMB, RING, PALM
};

/**
 * function to print registered mouse events to the terminal
 * @param buf
 */
void print_event(char *buf)
{
        // button state updated in 4th buffer slot; 1 = pressed, 0 = released
        char st = buf[4];

        // button ID stored in 2nd buffer slot; refer to ID enumerator
        switch (buf[2]) {
        case LEFT:
                printf("Button: Left\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case RIGHT:
                printf("Button: Right\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case MIDDLE:
                printf("Button: Middle\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case BACK:
                printf("Button: Back\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case FORWARD:
                printf("Button: Forward\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case THUMB:
                printf("Button: Thumb\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case RING:
                printf("Button: Ring\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        case PALM:
                printf("Button: Palm\t%s", st ? "PRESSED\n" : "RELEASED\n");
                break;
        default:
                // do nothing
                break;
        }
        return;
}

/**
 * function to print registered mouse events to the terminal
 * @param buf
 */
void play_event(char *buf)
{
        // button state updated in 4th buffer slot; 1 = pressed, 0 = released
        char st = buf[4];

        // button ID stored in 2nd buffer slot; refer to ID enumerator
        switch (buf[2]) {
        case LEFT:
                break;
        case RIGHT:
                break;
        case MIDDLE:
                break;
        case BACK:
                break;
        case FORWARD:
                break;
        case THUMB:
                break;
        case RING:
                break;
        case PALM:
                break;
        default:
                break;
        }
        return;
}
int main(int argc, char **argv)
{
        // open the device input stream
        FILE *mouse =
                        fopen("/dev/input/by-id/usb-ELECOM_TrackBall_Mouse_EX-G_Pro_TrackBall_A239231789-if01-event-mouse",
                              "r");

        char buf[BUF_LEN];

        // verify pipe
        if (mouse == NULL) {
                printf("Error: Device input stream not found... exiting.");
                exit(EXIT_FAILURE);
        }
        int counter = 0;
        while (1) {
                // read in raw input data from buffer
                fread(buf, BUF_LEN, 1, mouse);
                counter++;
                int buf_sum = 0;

                // reset buffer when end of transmission detected
                for (int i = 0; i < BUF_LEN; i++)
                        buf_sum += buf[i];
                if (buf_sum == 0)
                        counter = 0;

                // button presses reported in buffer 6 of 9
                if (counter % 9 == 6) {
                        if (DEBUG)
                                print_event(buf);
                        play_event(buf);
                }
        }

        // close the pipe to the input stream
        fclose(mouse);
}
