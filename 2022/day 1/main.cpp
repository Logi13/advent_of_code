#include <QCoreApplication>
#include <algorithm>

#include "QFile"

QString returnTextFileData(const QString &filePath) {
    QFile file(filePath);
    QString data;
    if(file.open(QFile::ReadOnly)) {
        data = file.readAll();
        file.close();
    }
    return data;
}

void day1PartOne() {
    QStringList stringDataValues = returnTextFileData(":/data/advent_day1_data").split("\r\n");
    QList<int> calories;

    int maxCalories = 0;
    int topThreeCalories = 0;

    int currentCalories = 0;
    const int lstCount = stringDataValues.count();
    for(int i = 0; i < lstCount; i++) {
        if(stringDataValues.at(i).isEmpty()) {
            calories.append(currentCalories);
            if(currentCalories > maxCalories) {
                maxCalories = currentCalories;
            }
            currentCalories = 0;
            continue;
        }
        currentCalories += stringDataValues.at(i).toInt();
    }
    // pick up any leftover calories if end of list does not have an empty line
    if(currentCalories > 0) {
        calories.append(currentCalories);
    }
    // sort the calories in the list
    std::sort(calories.begin(), calories.end());
    topThreeCalories = calories[calories.count() - 1] + calories[calories.count() - 2] + calories[calories.count() -3];
    qWarning() << "Max Calories: " << maxCalories << "Top 3 calories" << topThreeCalories;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    day1PartOne();

    return a.exec();
}
