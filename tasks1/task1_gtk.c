//
// Created by bczhc on 27/10/22.
//

#include <gtk/gtk.h>
#include "lib.h"

typedef struct {
    GtkEntry *length_input;
    GtkEntry *width_input;
    GtkLabel *output_label;
} Data;

static Data *shared_data;

void calc_button_clicked(GtkWidget *_button, gpointer data_ptr) {
    (void) _button;

    Data *data = (Data *) data_ptr;
    GtkLabel *output_label = data->output_label;

    GtkEntryBuffer *length_buffer = gtk_entry_get_buffer(data->length_input);
    const char *length_text = gtk_entry_buffer_get_text(length_buffer);
    GtkEntryBuffer *width_buffer = gtk_entry_get_buffer(data->width_input);
    const char *width_text = gtk_entry_buffer_get_text(width_buffer);

    i64 length, width;
    enum ParseIntResult length_result = parse_int(length_text, &length);
    enum ParseIntResult width_result = parse_int(width_text, &width);

    if (length_result == PIE_NO_DIGITS || width_result == PIE_NO_DIGITS) {
        gtk_label_set_label(output_label, "输入不合法");
        return;
    }

    if (length_result == PIE_OUT_OF_RANGE || width_result == PIE_OUT_OF_RANGE) {
        gtk_label_set_label(output_label, "输入范围太大");
        return;
    }
    assert(length_result == PIE_OK && width_result == PIE_OK);

    if (length < 0 || width < 0) {
        gtk_label_set_label(output_label, "请输入正数");
        return;
    }

    u64 area;
    if (rectangle_area(length, width, &area)) {
        gtk_label_set_label(output_label, "计算溢出");
        return;
    }

    char *text = "矩形的面积为：";
    size_t str_buf_size = strlen(text) + 20 /* length of U64_MAX */ + 1 /* '\0' */;
    char format_str[str_buf_size];
    sprintf(format_str, "%s%lu", text, area);

    gtk_label_set_label(output_label, format_str);
}

void activate(GtkApplication *app, gpointer _data) {
    (void) _data;

    GtkBuilder *ui_builder = gtk_builder_new_from_file(BUILDER_FILE);
    GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(ui_builder, "window"));

    gtk_window_set_application(window, app);
    gtk_window_set_title(window, "长方形面积计算");
    gtk_window_set_default_size(window, 500, 200);

    GtkEntry *length_input = GTK_ENTRY(gtk_builder_get_object(ui_builder, "length"));
    GtkEntry *width_input = GTK_ENTRY(gtk_builder_get_object(ui_builder, "width"));
    GtkButton *calc_button = GTK_BUTTON(gtk_builder_get_object(ui_builder, "calc"));
    GtkLabel *output = GTK_LABEL(gtk_builder_get_object(ui_builder, "output"));

    shared_data = (Data *) malloc(sizeof(Data));
    shared_data->length_input = length_input;
    shared_data->width_input = width_input;
    shared_data->output_label = output;

    g_signal_connect(calc_button, "clicked", G_CALLBACK(calc_button_clicked), shared_data);

    gtk_widget_show(GTK_WIDGET(window));
}

int main() {
    GtkApplication *app;
    app = gtk_application_new("pers.zhc.gtk", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), 0, NULL);

    g_object_unref(app);
    free(shared_data);

    return status;
}
