#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <xlnt/xlnt.hpp>



using namespace std;


int main() {


    cout << "\nWorked YAY" << endl << endl;

    // Load the workbook
    xlnt::workbook wb;
    wb.load("example.xlsx");

    // Select the active sheet
    xlnt::worksheet ws = wb.active_sheet();

    // Specify the column you want to read (0-based index, so column B is index 1)
    int column_index = 1; // Column B

    // Iterate over the rows and read the specific column
    for (auto row : ws.rows(false)) {
        if (column_index < row.length()) {
            auto cell = row[column_index];
            std::cout << cell.to_string() << std::endl;
        }
    }



    cout << "\n\nEnded Here" << endl << endl;

    return 0;
}