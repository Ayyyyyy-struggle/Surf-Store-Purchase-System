#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
using namespace std;

// Declare functions before main() 
void ShowUsage();
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTTotalXXXSmall, const int iTotalSmall,const int iTotalMedium, const int iTotalLarge);


// Execute main() with defining functions after main()
int main ()
{
    bool operation = true;       // Set up a condition for while loop
    char action;                 // User's selection to multiple questions
    int num_XXXS = 0;
    int num_S = 0;               // User's parchase amount for 3 sizes
    int num_M = 0;
    int num_L = 0;

    cout << setfill('*');
    cout << setw(61) << " " << endl;
    cout << setw(55) << " Welcome to my Johnny Utah's PointBreak Surf Shop "  << setw(6)  << " " << endl;
    cout << setw(62) << "\n\n" << endl;
    cout << endl;

    // Call out first function to show menu
    ShowUsage();

    while (operation == true)
    {
        cout << "\nPlease enter selection: ";
        cin >> action;
        action = toupper(action);             // Switch to capital letter to avoid case sensitive

        switch (action){
            case 'C':
                if (num_XXXS == 0 && num_S == 0 && num_M == 0 && num_L == 0) {       // No data entry, no purchase display
                    cout << "No purchases made yet." << endl;
                }
                else {
                    DisplayPurchase(num_XXXS, num_S, num_M, num_L);
                }
                break;
            case 'T': 
                if (num_XXXS == 0 && num_S == 0 && num_M == 0 && num_L == 0) {       // No data entry, no purchase display
                    cout << "No purchases made yet." << endl;
                }
                else {
                    DisplayTotal(num_XXXS, num_S, num_M, num_L);
                }
                break;
            case 'P':
                MakePurchase(num_XXXS, num_S, num_M, num_L);
                break;
            case 'S':
                ShowUsage();
                break;
            case 'Q':
                cout << "Thank you" << endl;
                operation = false;               // Return operation as false so loop ends
                break;
        }
    }

    cout << "Press any key to continue . . ." << endl;
    cin.ignore();
    cin.get();
    return 0;
}

// Define function to show the user how to use the program. Action code "s"
void ShowUsage() 
{
    cout << "To show program usage 'S' " << endl;
    cout << "To purchase a surfboard press 'P' " << endl;
    cout << "To display current purchases press 'C' " << endl;
    cout << "To display total amount due press 'T' " << endl;
    cout << "To quit the program press 'Q' \n" << endl;
}

// Define a function to sell surfboard, action code "p"
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    char type;        // Declare local variables
    int quantity;

    cout << "Please enter the quantity and type (X=squirrel Small, S=small, M=medium, L=Large) of surfboard you would like to purchase: ";
    cin >> quantity >> type;
    type = toupper(type);

    switch (type)
    {
        case 'S':
            iTotalSmall = iTotalSmall + quantity;        // Referring total amount not just single purchase
            break;
        case 'M':
            iTotalMedium = iTotalMedium + quantity;
            break;
        case 'L':
            iTotalLarge = iTotalLarge + quantity;
            break;
        case 'X':
            iTotalXXXSmall = iTotalXXXSmall + quantity;
    }

}

// Define a function to show the number of surfboards of eeach size sold, action code "c"
void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    // Only display items that have been purchased
    if (iTotalSmall > 0){
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0){
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0){
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (iTotalXXXSmall > 0){
        cout << "The total number of extra extra extra small squirrel surfboards is " << iTotalXXXSmall << endl;
    }

}

//  Define a function to show the total amount of money made, action code "t"
void DisplayTotal(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    const int XXXSmallPrice = 150;
    const int SmallPrice = 175;
    const int MediumPrice = 190;
    const int LargePrice = 200;
    double Total_XXXSmall = 0.0;
    double Total_Small=0.0;
    double Total_Medium=0.0;
    double Total_Large=0.0;
    double Total=0.0;

    cout << fixed << showpoint;
    cout << setprecision(2);

    // Only display purchased items and total amount
    if (iTotalXXXSmall > 0){
        Total_XXXSmall = iTotalXXXSmall * XXXSmallPrice;
        cout << "The total number of extra extra extra small squirrel surfboards is " << iTotalXXXSmall << " at a total of $" << Total_XXXSmall << endl;
    }
    if (iTotalSmall > 0){
        Total_Small = iTotalSmall * SmallPrice;
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << Total_Small << endl;
    }
    if (iTotalMedium > 0){
        Total_Medium = iTotalMedium * MediumPrice;
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << Total_Medium << endl;
    }
    if (iTotalLarge > 0){
        Total_Large = iTotalLarge * LargePrice;
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << Total_Large << endl;
    }
    
    Total = Total_XXXSmall + Total_Small + Total_Medium + Total_Large;
    cout << "Amount due: $" << Total << endl;

}