#include "Instructor.h"
#include <fstream>

#include <iomanip>




Instructor::Instructor() {

}
void Instructor::writearray()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << timetable[i][j] << " ";
            count++;
            if (count % 6 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
}


void Instructor::writetimetable(std::string instructorName,int ID, int days[30])
{
    std::ofstream schedule("resources/Files/timetable.txt", std::ios::app);
    schedule << instructorName << ID << ":\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < column; j++)
        {
            bool isChoiceDay = false;
            for (int k = 0; k < 30; k++)
            {
                if (timetable[i][j] == days[k])
                {
                    isChoiceDay = true;
                    break;
                }
            }
            if (isChoiceDay)
            {
                schedule <<  timetable[i][j] << ID << std::setw(6) << " ";
            }
            else
            {
                schedule <<  timetable[i][j] << std::setw(8) << " ";

            }
            if ((j + 1) % 6 == 0)
            {
                schedule << std::endl;
            }
        }
    }
    schedule << std::endl;
    schedule.close();
}

void Instructor::setSchedule() {

   std:: ifstream read("resources/Files/timetable.txt");
   std::string output;
    read >> output;
   std:: cout << output;
    while (!read.eof()) // Continue if not end of file
    {
        getline(read, output, '\n');
        std::cout << output << std::endl;
    }
    read.close();


}