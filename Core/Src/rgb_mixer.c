#include "rgb_mixer.h"

enum {
	SLIDER_R = 0, SLIDER_G, SLIDER_B
};

typedef struct {
	uint8_t slider_type;
	lv_obj_t *label;
} rgb_mixer_t;

rgb_mixer_t r, g, b;
lv_obj_t *rect;
lv_obj_t *slider_r, *slider_g, *slider_b;
int8_t enable_timer_button_flag = 0;
lv_obj_t *enable_timer_button;
lv_obj_t *enable_timer_button_label;
lv_timer_t * timer1;

void slider_callback(lv_event_t *e) {
	static uint8_t r, g, b;
	lv_obj_t *slider = lv_event_get_target(e);
	rgb_mixer_t *user_data = lv_event_get_user_data(e);
	int32_t value = lv_slider_get_value(slider);
	lv_label_set_text_fmt(user_data->label, "%ld", value);
	if (user_data->slider_type == SLIDER_R) {
		r = value;
	} else if (user_data->slider_type == SLIDER_G) {
		g = value;
	} else if (user_data->slider_type == SLIDER_B) {
		b = value;
	}

	lv_obj_set_style_bg_color(rect, lv_color_make(r, g, b), LV_PART_MAIN);
}

void timer_button_callback(lv_event_t *e){
	if (!enable_timer_button_flag){
		enable_timer_button_flag = 1;
		lv_timer_resume(timer1);
		lv_label_set_text(enable_timer_button_label, "Manual");
	} else {
		enable_timer_button_flag = 0;
		lv_timer_pause(timer1);
		lv_label_set_text(enable_timer_button_label, "Auto");
	}
}

void timer_callback(struct _lv_timer_t *timer) {
	uint8_t r1, g1, b1;
	r1 = lv_rand(0, 255);
	g1 = lv_rand(0, 255);
	b1 = lv_rand(0, 255);
	lv_label_set_text_fmt(r.label, "%d", r1);
	lv_label_set_text_fmt(g.label, "%d", g1);
	lv_label_set_text_fmt(b.label, "%d", b1);
	lv_slider_set_value(slider_r, r1, LV_ANIM_ON);
	lv_slider_set_value(slider_g, g1, LV_ANIM_ON);
	lv_slider_set_value(slider_b, b1, LV_ANIM_ON);
	lv_obj_set_style_bg_color(rect, lv_color_make(r1, g1, b1), LV_PART_MAIN);
}

void rgb_mixer_create_ui() {
	lv_obj_t *act_scr = lv_scr_act();

	r.slider_type = SLIDER_R;
	g.slider_type = SLIDER_G;
	b.slider_type = SLIDER_B;

	slider_r = lv_slider_create(act_scr);
	lv_obj_set_width(slider_r, 400);
	lv_slider_set_range(slider_r, 0, 255);
	lv_obj_align(slider_r, LV_ALIGN_TOP_MID, 0, 60);
	lv_obj_set_style_bg_color(slider_r, lv_palette_main(LV_PALETTE_RED),
			LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(slider_r, lv_palette_main(LV_PALETTE_RED),
			LV_PART_KNOB);

	slider_g = lv_slider_create(act_scr);
	lv_obj_set_width(slider_g, 400);
	lv_slider_set_range(slider_g, 0, 255);
	lv_obj_align_to(slider_g, slider_r, LV_ALIGN_TOP_MID, 0, 40);
	lv_obj_set_style_bg_color(slider_g, lv_palette_main(LV_PALETTE_GREEN),
			LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(slider_g, lv_palette_main(LV_PALETTE_GREEN),
			LV_PART_KNOB);

	slider_b = lv_slider_create(act_scr);
	lv_obj_set_width(slider_b, 400);
	lv_slider_set_range(slider_b, 0, 255);
	lv_obj_align_to(slider_b, slider_g, LV_ALIGN_TOP_MID, 0, 40);
	lv_obj_set_style_bg_color(slider_b, lv_palette_main(LV_PALETTE_BLUE),
			LV_PART_INDICATOR);
	lv_obj_set_style_bg_color(slider_b, lv_palette_main(LV_PALETTE_BLUE),
			LV_PART_KNOB);

	rect = lv_obj_create(act_scr);
	lv_obj_set_size(rect, 400, 80);
	lv_obj_align_to(rect, slider_b, LV_ALIGN_TOP_MID, 0, 30);
	lv_obj_set_style_border_color(rect, lv_color_black(), LV_PART_MAIN);
	lv_obj_set_style_border_width(rect, 5, LV_PART_MAIN);

	enable_timer_button = lv_btn_create(act_scr);
	lv_obj_set_size(enable_timer_button, 200, 50);
	lv_obj_align_to(enable_timer_button, rect, LV_ALIGN_TOP_MID, 0, 70);
	lv_obj_set_style_bg_color(enable_timer_button, lv_palette_main(LV_PALETTE_DEEP_ORANGE), LV_PART_MAIN);
	enable_timer_button_label = lv_label_create(enable_timer_button);
	lv_label_set_text(enable_timer_button_label, "Auto");
	lv_obj_center(enable_timer_button_label);
	lv_obj_set_style_text_font(enable_timer_button_label, &lv_font_montserrat_20, LV_PART_MAIN);
	lv_obj_add_flag(enable_timer_button, LV_OBJ_FLAG_CHECKABLE);

	lv_obj_t *heading = lv_label_create(act_scr);
	lv_label_set_text(heading, "RGB Mixer");
	lv_obj_align(heading, LV_ALIGN_TOP_MID, 0, 10);
	lv_obj_set_style_text_font(heading, &lv_font_montserrat_24, LV_PART_MAIN);

	r.label = lv_label_create(act_scr);
	lv_label_set_text(r.label, "0");
	lv_obj_align_to(r.label, slider_r, LV_ALIGN_TOP_MID, 0, -20);
	lv_obj_set_style_text_font(r.label, &lv_font_montserrat_16, LV_PART_MAIN);

	g.label = lv_label_create(act_scr);
	lv_label_set_text(g.label, "0");
	lv_obj_align_to(g.label, slider_g, LV_ALIGN_TOP_MID, 0, -20);
	lv_obj_set_style_text_font(g.label, &lv_font_montserrat_16, LV_PART_MAIN);

	b.label = lv_label_create(act_scr);
	lv_label_set_text(b.label, "0");
	lv_obj_align_to(b.label, slider_b, LV_ALIGN_TOP_MID, 0, -20);
	lv_obj_set_style_text_font(b.label, &lv_font_montserrat_16, LV_PART_MAIN);

	// Set callback
	lv_obj_add_event_cb(slider_r, slider_callback, LV_EVENT_VALUE_CHANGED, &r);
	lv_obj_add_event_cb(slider_g, slider_callback, LV_EVENT_VALUE_CHANGED, &g);
	lv_obj_add_event_cb(slider_b, slider_callback, LV_EVENT_VALUE_CHANGED, &b);
	lv_obj_add_event_cb(enable_timer_button, timer_button_callback, LV_EVENT_VALUE_CHANGED, NULL);

	timer1 = lv_timer_create(timer_callback, 1000, NULL);
	if (!enable_timer_button_flag){
		lv_timer_pause(timer1);
	}

}
