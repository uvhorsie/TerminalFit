#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QPixmap>
#include "signuppage.h"
#include "signinpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QLabel for the title
    QLabel *titleLabel = new QLabel("Terminal Fit", this);
    QFont titleFont("Times New Roman", 60);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    // Load the image from the resource file
    QPixmap image("C:/Users/james/OneDrive/Pictures/terminalfit.png");


    // Create a QLabel for displaying the image
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);

    // Create buttons
    QPushButton *signUpButton = new QPushButton("Sign Up", this);
    QPushButton *signInButton = new QPushButton("Sign In", this);

    // Connect the "Sign Up" button to the slot for sign-up
    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::openSignUpPage);

    // Connect the "Sign In" button to the slot for sign-in
    connect(signInButton, &QPushButton::clicked, this, &MainWindow::openSignInPage);

    // Customize button size
    signUpButton->setFixedSize(100, 30);
    signInButton->setFixedSize(100, 30);

    // Set the text color to white and background to black for the buttons
    QString buttonStyle = "QPushButton { background-color: black; color: white; border: 2px solid white; }";
    signUpButton->setStyleSheet(buttonStyle);
    signInButton->setStyleSheet(buttonStyle);

    // Create a layout for the title
    QVBoxLayout *titleLayout = new QVBoxLayout;
    titleLayout->addWidget(titleLabel);

    // Create a layout for the buttons at the bottom
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(signUpButton);
    buttonLayout->addWidget(signInButton);
    buttonLayout->addStretch(1);

    // Create a central layout for the title, image, and buttons
    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(titleLayout);
    centralLayout->addWidget(imageLabel);
    centralLayout->addLayout(buttonLayout);

    // Set the text color to white and background to black for the central widget
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(centralLayout);
    centralWidget->setStyleSheet("background-color: black; color: white;");
    setCentralWidget(centralWidget);

    QPixmap appIcon("C:/Users/james/OneDrive/Pictures/terminalfit.png");
    setWindowIcon(appIcon);

}

void MainWindow::openSignUpPage()
{
    // Create an instance of the sign-up page
    SignUpPage *signUpPage = new SignUpPage(this);

    // Set the sign-up page as the central widget to navigate to it
    setCentralWidget(signUpPage);
}

void MainWindow::openSignInPage()
{
    // Create an instance of the sign-in page
    SignInPage *signInPage = new SignInPage(this);

    // Set the sign-in page as the central widget to navigate to it
    setCentralWidget(signInPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
