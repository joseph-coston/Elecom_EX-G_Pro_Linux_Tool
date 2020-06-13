/**
 * @file yaml_loader.h
 *
 * @date Jun 13, 2020
 * @author joseph
 */

#ifndef YAML_LOADER_H_
#define YAML_LOADER_H_

struct Conf {
        char *LeftClickDown;
        char *LeftClickUp;

        char *RightClickDown;
        char *RightClickUp;

        char *MiddleClickDown;
        char *MiddleClickUp;

        char *RingClickDown;
        char *RingClickUp;

        char *ThumbClickDown;
        char *ThumbClickUp;

        char *PalmClickDown;
        char *PalmClickUp;

        char *ForwardClickDown;
        char *ForwardClickUp;

        char *BackClickDown;
        char *BackClickUp;
};

typedef struct Conf CONFIG;

CONFIG* readConf(char *filename);

#endif /* YAML_LOADER_H_ */
