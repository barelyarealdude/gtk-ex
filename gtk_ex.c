// GTK starting usage??

// compilation commands --- gcc `pkg-config --cflags gtk+-3.0` -o gtk_ex gtk_ex.c `pkg-config --libs gtk+-3.0`

#include <gtk/gtk.h>

static void activate (GtkApplication * app, gpointer user_data) {
	GtkWidget * window;
	
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Title");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;
	app = gtk_application_new("io.github.barelyarealdude.gtk_ex", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	
	return status;
}