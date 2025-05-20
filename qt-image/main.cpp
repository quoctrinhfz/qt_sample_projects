#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;
    label.setWindowTitle("Image Viewer");

    // Load the image (embedded using Qt Resource System)
    QPixmap pixmap(":/images/sample.jpg"); // Replace with your image path

    if (pixmap.isNull()) {
        label.setText("Failed to load the image!");
    } else {
        label.setPixmap(pixmap);
        label.setScaledContents(true); // Scale image to fit the label
        label.resize(pixmap.size());   // Adjust label size to the image size
    }

    label.show();
    return app.exec();
}
