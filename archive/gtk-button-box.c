#include <gtk/gtk.h>

static void createUI(GtkWidget *window) {
	GtkWidget *btn_box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
	GtkWidget *btn = gtk_button_new_with_label("Hello, world");
	GtkWidget *btn2 = gtk_button_new_with_label("Exit");
	gtk_container_add(GTK_CONTAINER(window), btn_box);
	gtk_container_add(GTK_CONTAINER(btn_box), btn);
	gtk_container_add(GTK_CONTAINER(btn_box), btn2);
}

static void activate(GtkApplication* app, gpointer user_data) {
	GtkWidget *window = gtk_application_window_new(app);
	createUI(window);
	gtk_window_set_title(GTK_WINDOW(window), "My Cool App");
	gtk_window_set_default_size(GTK_WINDOW(window), 500,500);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app; 
	app = gtk_application_new("io.dougie.app", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	int status = g_application_run(G_APPLICATION(app), argc, argv);

	g_object_unref(app);
	return status;
}
