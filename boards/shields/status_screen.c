#include <zmk/display.h>
#include <lvgl.h>

LV_IMG_DECLARE(logo_img); // объявление картинки (добавим позже)

static lv_obj_t *label;
static lv_obj_t *img;
static lv_timer_t *timer;
static int frame = 0;

static void anim_cb(lv_timer_t *t) {
    frame++;
    lv_label_set_text_fmt(label, "Frame: %d", frame);
    lv_obj_set_y(img, (frame % 10) - 5); // простая анимация "прыжка" логотипа
}

void zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);

    img = lv_img_create(screen);
    lv_img_set_src(img, &logo_img);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, -5);

    label = lv_label_create(screen);
    lv_label_set_text(label, "ZMK + Sofle!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 15);

    timer = lv_timer_create(anim_cb, 150, NULL);
    lv_scr_load(screen);
}
