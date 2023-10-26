#include "signinpage.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout> // Include QHBoxLayout
#include <QSettings>
#include <QFile>

#include "mainwindow.h" // Include the header for your MainWindow class

SignInPage::SignInPage(QWidget *parent) : QWidget(parent)
{
    QLabel *titleLabel = new QLabel("Welcome Back", this);
    titleLabel->setFont(QFont("Times New Roman", 30));
    titleLabel->setAlignment(Qt::AlignCenter);

    QLabel *usernameLabel = new QLabel("Username:", this);
    usernameLineEdit = new QLineEdit(this); // Made this a member variable
    usernameLineEdit->setFixedSize(200, 30);

    QLabel *passwordLabel = new QLabel("Password:", this);
    passwordLineEdit = new QLineEdit(this); // Made this a member variable
    passwordLineEdit->setFixedSize(200, 30);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton *signInButton = new QPushButton("Sign In", this);
    signInButton->setFixedSize(100, 30);
    connect(signInButton, &QPushButton::clicked, this, &SignInPage::signIn); // Connect the button to signIn function

    QPushButton *backButton = new QPushButton("Back", this);
    connect(backButton, &QPushButton::clicked, this, &SignInPage::goBackToMainPage);
    backButton->setFixedSize(100, 30);

    QSettings settings("MyApp", "MyAppSettings");
    QString savedUsername = settings.value("Username").toString();
    QString savedPassword = settings.value("Password").toString();
    usernameLineEdit->setText(savedUsername);
    passwordLineEdit->setText(savedPassword);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(signInButton);
    buttonLayout->addWidget(backButton);

    layout->addLayout(buttonLayout);
    signInButton->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 20px;");
    backButton->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 20px;");

    QPixmap appIcon("C:/Users/james/OneDrive/Pictures/terminalfit.png");
    setWindowIcon(appIcon);

    setLayout(layout);
}

void SignInPage::goBackToMainPage()
{
    //Assuming MainWindow is your main page, navigate back to it
    MainWindow *mainWindow = new MainWindow;
    this->hide(); // Hide the sign-in page
    mainWindow->show(); // Show the main page
}

void SignInPage::checkUserCredentials(const QString &username, const QString &password)
{
    // Open the text file for reading
    QFile file("user_credentials.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        bool found = false;

        // Read the file line by line and compare entered credentials
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() == 2)
            {
                QString storedUsername = parts[0];
                QString storedPassword = parts[1];

                if (username == storedUsername && password == storedPassword)
                {
                    // Authentication successful
                    found = true;
                    break;
                }
            }
        }

        if (found)
        {
            // Navigate to the main page
            MainWindow *mainWindow = new MainWindow;
            this->hide();
            mainWindow->show();
        }
        else
        {
            // Display an error message for failed authentication
            // Handle this according to your application's requirements
        }

        file.close();
    }
}

void SignInPage::signIn()
{
    // Get the entered username and password
    QString enteredUsername = usernameLineEdit->text();
    QString enteredPassword = passwordLineEdit->text();

    // Check user credentials against the text file
    checkUserCredentials(enteredUsername, enteredPassword);
}


