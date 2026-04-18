
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // 👨‍💼 Bureaucrats
    Bureaucrat high("High", 1);      // قوي بزاف
    Bureaucrat mid("Mid", 100);      // متوسط
    Bureaucrat low("Low", 150);      // ضعيف

    // 🌳 1. Shrubbery → SUCCESS
    // try
    // {
    //     ShrubberyCreationForm shrub("home");
    //     high.signForm(shrub);
    //     high.executeForm(shrub);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Shrubbery error: " << e.what() << std::endl;
    // }

    // std::cout << "---------------------\n";

    // 🤖 2. Robotomy → FAIL (execution grade ضعيف)
    try
    {
        RobotomyRequestForm robot("Bender");
        mid.signForm(robot);        // ممكن يوقع
        mid.executeForm(robot);     // غادي يفشل (grade ماكافيش)
    }
    catch (std::exception &e)
    {
        std::cout << "Robotomy error: " << e.what() << std::endl;
    }

    std::cout << "---------------------\n";

    // // 👑 3. Presidential → FAIL (sign grade ضعيف)
    // try
    // {
    //     PresidentialPardonForm pres("Arthur Dent");
    //     low.signForm(pres);         // غادي يفشل
    //     high.executeForm(pres);     // حتى لو حاول، راه ما موقعاش
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Presidential error: " << e.what() << std::endl;
    // }

    // return 0;
}
// ```

// ---

// ## 🎯 شنو غادي يوقع

// ### 🌳 Shrubbery

// ✔️ high عندو grade 1
// → sign ✔️
// → execute ✔️
// → يتخلق file فيه trees 🌳

// ---

// ### 🤖 Robotomy

// ✔️ mid يقدر يوقع
// ❌ ولكن execute خاصو 45 وهو 100
// → exception ❌

// ---

// ### 👑 Presidential

// ❌ low (150) ما يقدرش يوقع (خاص 25)
// → exception من الأول ❌

// ---

// ## 🔥 هاد main كيغطي:

// * success case ✔️
// * fail sign ❌
// * fail execute ❌

// ---

// إلا بغيتي نزيد:
// 👉 test فيه robotomy success/fail 50%
// 👉 ولا output المتوقع باش تقارن مع project ديالك

// قولها 👍


