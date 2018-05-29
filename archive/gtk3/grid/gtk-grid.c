#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
	g_print("Hello world from g_print\n");
}

static void createUI(GtkWidget *window) {
	GtkWidget *btn;
	GtkWidget *btn2;
	GtkWidget *btn3;
	GtkWidget *btn_quit;
	GtkWidget *grid;

	gtk_container_set_border_width(GTK_CONTAINER(window), 50);

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	btn = gtk_button_new_with_label("Button 1");
	g_signal_connect(btn, "clicked", G_CALLBACK(print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), btn, 0, 0, 1, 1);

	btn2 = gtk_button_new_with_label("Button 2");
	gtk_grid_attach(GTK_GRID(grid), btn2, 1, 0, 2, 1);

	btn3 = gtk_button_new_with_label("Button 3");
	gtk_grid_attach(GTK_GRID(grid), btn3, 1, 1, 1, 1);

	btn_quit = gtk_button_new_with_label("Quit");
	g_signal_connect(btn_quit, "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
	gtk_grid_attach(GTK_GRID(grid), btn_quit, 2, 1, 1, 1);
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
