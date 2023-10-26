#include "dashboardpage.h"
#include "mainwindow.h"
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>

DashboardPage::DashboardPage(QWidget *parent) : QWidget(parent)
{
    // Create a tab widget to organize the content
    QTabWidget *tabWidget = new QTabWidget(this);

    // Create tab pages for Profile Manager, Workouts, Calorie Tracker, Calorie Calculator, Statistics, and Settings
    QWidget *profileManagerTab = new QWidget;
    QWidget *workoutsTab = new QWidget;
    QWidget *calorieTrackerTab = new QWidget;
    QWidget *calorieCalculatorTab = new QWidget;
    QWidget *statisticsTab = new QWidget;
    QWidget *settingsTab = new QWidget;

    // Customize each tab's content
    QVBoxLayout *profileManagerLayout = new QVBoxLayout;
    QLabel *profileManagerLabel = new QLabel("Welcome", this);
    profileManagerLayout->addWidget(profileManagerLabel);
    profileManagerTab->setLayout(profileManagerLayout);

    QVBoxLayout *workoutsLayout = new QVBoxLayout;
    QLabel *workoutsLabel = new QLabel("Placeholder content for Workouts", this);
    workoutsLayout->addWidget(workoutsLabel);
    workoutsTab->setLayout(workoutsLayout);

    QVBoxLayout *calorieTrackerLayout = new QVBoxLayout;
    QLabel *calorieTrackerLabel = new QLabel("Placeholder content for Calorie Tracker", this);
    calorieTrackerLayout->addWidget(calorieTrackerLabel);
    calorieTrackerTab->setLayout(calorieTrackerLayout);

    // Customize the content for the Calorie Calculator tab
    QVBoxLayout *calorieCalculatorLayout = new QVBoxLayout;
    calorieCalculatorTab->setLayout(calorieCalculatorLayout);

    // Create widgets for the calorie calculator
    QLabel *calorieCalculatorLabel = new QLabel("Calorie Calculator", calorieCalculatorTab);
    calorieCalculatorLabel->setFont(QFont("Arial", 16, QFont::Bold));

    QLabel *weightLabel = new QLabel("Weight (lbs):", calorieCalculatorTab);
    QLineEdit *weightInput = new QLineEdit(calorieCalculatorTab);

    QLabel *heightLabel = new QLabel("Height (in):", calorieCalculatorTab);
    QLineEdit *heightInput = new QLineEdit(calorieCalculatorTab);

    QLabel *ageLabel = new QLabel("Age:", calorieCalculatorTab);
    QLineEdit *ageInput = new QLineEdit(calorieCalculatorTab);

    QRadioButton *maleRadioButton = new QRadioButton("Male", calorieCalculatorTab);
    QRadioButton *femaleRadioButton = new QRadioButton("Female", calorieCalculatorTab);

    QLabel *resultLabel = new QLabel("Estimated Calorie Needs:", calorieCalculatorTab);
    QLabel *calorieResult = new QLabel(calorieCalculatorTab);

    QPushButton *calculateButton = new QPushButton("Calculate", calorieCalculatorTab);

    // Add widgets to the layout
    calorieCalculatorLayout->addWidget(calorieCalculatorLabel);
    calorieCalculatorLayout->addWidget(weightLabel);
    calorieCalculatorLayout->addWidget(weightInput);
    calorieCalculatorLayout->addWidget(heightLabel);
    calorieCalculatorLayout->addWidget(heightInput);
    calorieCalculatorLayout->addWidget(ageLabel);
    calorieCalculatorLayout->addWidget(ageInput);
    calorieCalculatorLayout->addWidget(maleRadioButton);
    calorieCalculatorLayout->addWidget(femaleRadioButton);
    calorieCalculatorLayout->addWidget(calculateButton);
    calorieCalculatorLayout->addWidget(resultLabel);
    calorieCalculatorLayout->addWidget(calorieResult);

    // Connect the Calculate button to a slot
    connect(calculateButton, &QPushButton::clicked, this, &DashboardPage::calculateCalories);

    QVBoxLayout *statisticsLayout = new QVBoxLayout;
    QLabel *statisticsLabel = new QLabel("Placeholder content for Statistics", this);
    statisticsLayout->addWidget(statisticsLabel);
    statisticsTab->setLayout(statisticsLayout);

    QVBoxLayout *settingsLayout = new QVBoxLayout;
    QLabel *settingsLabel = new QLabel("Placeholder content for Settings", this);
    settingsLayout->addWidget(settingsLabel);
    settingsTab->setLayout(settingsLayout);

    // Add tabs to the tab widget
    tabWidget->addTab(profileManagerTab, "Profile Manager");
    tabWidget->addTab(workoutsTab, "Workouts");
    tabWidget->addTab(calorieTrackerTab, "Calorie Tracker");
    tabWidget->addTab(calorieCalculatorTab, "Calorie Calculator");
    tabWidget->addTab(statisticsTab, "Statistics");
    tabWidget->addTab(settingsTab, "Settings");

    tabWidget->setTabPosition(QTabWidget::South);
    tabWidget->setStyleSheet("QTabWidget::pane { border: 2px solid #555; background-color: #f9f9f9; }");

    // Create a logout button
    QPushButton *logoutButton = new QPushButton("Logout", this);
    connect(logoutButton, &QPushButton::clicked, this, &DashboardPage::goBackToMainPage);
    logoutButton->setStyleSheet("background-color: #f44336; color: white;");

    // Create a layout for the entire dashboard page
    QVBoxLayout *dashboardLayout = new QVBoxLayout;
    dashboardLayout->addWidget(tabWidget);
    dashboardLayout->addWidget(logoutButton);

    QFont commonFont("Arial", 12);
    profileManagerLabel->setFont(commonFont);
    logoutButton->setFont(commonFont);

    // Set the background color
    setStyleSheet("background-color: #f9f9f9;");

    QPixmap appIcon("C:/Users/james/OneDrive/Pictures/terminalfit.png");
    setWindowIcon(appIcon);

    // Set the layout for the dashboard page
    setLayout(dashboardLayout);

    setFixedSize(800, 600);
}

void DashboardPage::calculateCalories()
{
    double weightInLbs = weightInput->text().toDouble();
    double heightInInches = heightInput->text().toDouble();
    int age = ageInput->text().toInt();

    // Convert weight to kilograms (1 lb = 0.453592 kg) and height to centimeters (1 inch = 2.54 cm)
    double weightInKg = weightInLbs * 0.453592;
    double heightInCm = heightInInches * 2.54;

    double calories = 0.0;

    if (maleRadioButton->isChecked()) {
        // Calculate calories for a male (replace with your formula)
        calories = 66.5 + (13.75 * weightInKg) + (5.003 * heightInCm) - (6.75 * age);
    } else if (femaleRadioButton->isChecked()) {
        // Calculate calories for a female (replace with your formula)
        calories = 655.1 + (9.56 * weightInKg) + (1.85 * heightInCm) - (4.68 * age);
    }

    calorieResult->setText("Estimated Calories: " + QString::number(calories));
}

void DashboardPage::goBackToMainPage()
{
    //Assuming MainWindow is your main page, navigate back to it
    MainWindow *mainWindow = new MainWindow;
    this->hide(); // Hide the sign-in page
    mainWindow->show(); // Show the main page
}

