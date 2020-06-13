/**
 * @file yaml_loader.c
 * @brief A library to load the yaml config file
 * @date Jun 13, 2020
 * @author Joseph Coston
 */
#include <stdio.h>
#include <string.h>
#include <yaml.h>


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

CONFIG* readConf(char *filename)
{
        FILE *fh = fopen(filename, "r");
        yaml_parser_t parser;
        yaml_token_t token;
        CONFIG *conf = malloc(sizeof(CONFIG));

        if (!yaml_parser_initialize(&parser))
                fputs("Failed to initialize parser!\n", stderr);
        if (fh == NULL)
                fputs("Failed to open file!\n", stderr);
        yaml_parser_set_input_file(&parser, fh);

        /* As this is an example, I'll just use:
         *  state = 0 = expect key
         *  state = 1 = expect value
         */
        int state = 0;
        char **datap;
        char *tk;

        do {
                yaml_parser_scan(&parser, &token);
                switch (token.type) {
                case YAML_KEY_TOKEN:
                        state = 0;
                        break;
                case YAML_VALUE_TOKEN:
                        state = 1;
                        break;
                case YAML_SCALAR_TOKEN:
                        tk = token.data.scalar.value;
                        if (state == 0) {
                                /* It's safe to not use strncmp as
                                 one string is a literal */
                                if (!strcmp(tk, "LeftClickDown")) {
                                        datap = &conf->LeftClickDown;
                                } else if (!strcmp(tk, "LeftClickUp")) {
                                        datap = &conf->LeftClickUp;
                                } else if (!strcmp(tk, "RightClickDown")) {
                                        datap = &conf->RightClickDown;
                                } else if (!strcmp(tk, "RightClickUp")) {
                                        datap = &conf->RightClickUp;
                                } else if (!strcmp(tk, "MiddleClickDown")) {
                                        datap = &conf->MiddleClickDown;
                                } else if (!strcmp(tk, "MiddleClickUp")) {
                                        datap = &conf->MiddleClickUp;
                                } else if (!strcmp(tk, "RingClickDown")) {
                                        datap = &conf->RingClickDown;
                                } else if (!strcmp(tk, "RingClickUp")) {
                                        datap = &conf->RingClickUp;
                                } else if (!strcmp(tk, "ThumbClickDown")) {
                                        datap = &conf->ThumbClickDown;
                                } else if (!strcmp(tk, "ThumbClickUp")) {
                                        datap = &conf->ThumbClickUp;
                                } else if (!strcmp(tk, "PalmClickDown")) {
                                        datap = &conf->PalmClickDown;
                                } else if (!strcmp(tk, "PalmClickUp")) {
                                        datap = &conf->PalmClickUp;
                                } else if (!strcmp(tk, "ForwardClickDown")) {
                                        datap = &conf->ForwardClickDown;
                                } else if (!strcmp(tk, "ForwardClickUp")) {
                                        datap = &conf->ForwardClickUp;
                                } else if (!strcmp(tk, "BackClickDown")) {
                                        datap = &conf->BackClickDown;
                                } else if (!strcmp(tk, "BackClickUp")) {
                                        datap = &conf->BackClickUp;
                                } else {
                                        printf("Unrecognized key: %s\n", tk);
                                }
                        } else {
                                *datap = strdup(tk);
                        }
                        break;
                default:
                        break;
                }
                if (token.type != YAML_STREAM_END_TOKEN)
                        yaml_token_delete(&token);
        } while (token.type != YAML_STREAM_END_TOKEN);

        yaml_token_delete(&token);
        yaml_parser_delete(&parser);
        fclose(fh);
        return conf;
}


