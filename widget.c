#include <gtk/gtk.h>
#include <stdlib.h>

static gboolean update_label(gpointer label) {
    char buffer[512];
    FILE *fp = popen("/home/kali/C/ptoccessor-info", "r");
    if (fp == NULL) {
        return TRUE;
    }
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        gtk_label_set_text(GTK_LABEL(label), buffer);
    }
    pclose(fp);
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *label = gtk_label_new("Loading...");
    gtk_container_add(GTK_CONTAINER(window), label);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

