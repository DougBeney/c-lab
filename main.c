#include <gtk/gtk.h>

void print_hello(GtkApplication *app, gpointer user_data) {
}

int main(int argc, char **argv) {
	GtkBuilder *builder;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("builder.ui");

	GObject *window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	GObject *quit_btn = gtk_builder_get_object(builder, "quit-button");
	g_signal_connect(quit_btn, "clicked", G_CALLBACK(print_hello), NULL);
	

	gtk_main();
	return 0;
}

