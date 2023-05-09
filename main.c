#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

#define SCREEN_W 800
#define SCREEN_H 600

void draw_jackpot(BITMAP* buffer, BITMAP* images[], int image1, int image2, int image3) {
    // Affichage des images aléatoires
    blit(images[image1], buffer, 0, 0, 80, 150, 200, 200);
    blit(images[image2], buffer, 0, 0, 310, 150, 200, 200);
    blit(images[image3], buffer, 0, 0, 540, 150, 200, 200);
}

int main() {
    // Initialisation d'Allegro
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_W, SCREEN_H, 0, 0);

    // Chargement des images
    BITMAP* jackpot = load_bitmap("jackpot.bmp", NULL);
    BITMAP* images[7];
    images[0] = load_bitmap("imgchiffre.bpm", NULL);
    images[1] = load_bitmap("imgsmiley.bpm", NULL);
    images[2] = load_bitmap("imgraisin.bmp", NULL);
    images[3] = load_bitmap("imgece.bmp", NULL);
    images[4] = load_bitmap("imgcerise.bmp", NULL);
    images[5] = load_bitmap("imgcitron.bmp", NULL);
    images[6] = load_bitmap("imgtreffle.bmp", NULL);

    // Création des buffers
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* image_buffer = create_bitmap(200, 200);

    // Variables pour l'animation
    int stop = 0;
    int image1 = 0, image2 = 0, image3 = 0;

    // Boucle principale
    while (!stop) {
        if (key[KEY_ESC]) {
            stop = 1;
        } else if (key[KEY_SPACE]) {
            // Génération aléatoire des images
            srand(time(NULL));
            image1 = rand() % 7;
            image2 = rand() % 7;
            image3 = rand() % 7;
        }

        // Affichage des images du jackpot et du fond
        draw_jackpot(buffer, images, image1, image2, image3);
        blit(jackpot, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        // Affichage du buffer
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    // Libération de la mémoire
    destroy_bitmap(jackpot);
    for (int i = 0; i < 7; i++) {
        destroy_bitmap(images[i]);
    }


    readkey();

    allegro_exit();
    return 0;
}
