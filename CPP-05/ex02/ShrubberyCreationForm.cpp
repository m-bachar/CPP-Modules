#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * ShrubberyCreationForm " << RESET << "default constructor called !" << std::endl;
	target = "Homenito";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Formax", false, 145, 137)
{
	std::cout << GREEN << " * ShrubberyCreationForm " << RESET << "parametrized constructor called !" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
    *this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    this->target = obj.target;
	return *this;
}

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getSignGrade() && !getSign())
		throw GradeTooLowException();
	std::ofstream	shruberryFile(target + "_shrubbery");
	if (shruberryFile.is_open()) {
		shruberryFile << "                                                         ." << "\n";
        shruberryFile << "                                     .         ;  " << "\n";
        shruberryFile << "         .              .              ;%     ;;   " << "\n";
        shruberryFile << "           ,           ,                :;%  %;   " << "\n";
        shruberryFile << "            :         ;                   :;%;'     .,   " << "\n";
        shruberryFile << "   ,.        %;     %;            ;        %;'    ,;" << "\n";
        shruberryFile << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << "\n";
        shruberryFile << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << "\n";
        shruberryFile << "       ;%;      %;        ;%;        % ;%;  ,%;'" << "\n";
        shruberryFile << "        `%;.     ;%;     %;'         `;%%;.%;'" << "\n";
        shruberryFile << "         `:;%.    ;%%. %@;        %; ;@%;%'" << "\n";
        shruberryFile << "            `:%;.  :;bd%;          %;@%;'" << "\n";
        shruberryFile << "              `@%:.  :;%.         ;@@%;'   " << "\n";
        shruberryFile << "                `@%.  `;@%.      ;@@%;         " << "\n";
        shruberryFile << "                  `@%%. `@%%    ;@@%;        " << "\n";
        shruberryFile << "                    ;@%. :@%%  %@@%;       " << "\n";
        shruberryFile << "                      %@bd%%%bd%%:;     " << "\n";
        shruberryFile << "                        #@%%%%%:;;" << "\n";
        shruberryFile << "                        %@@%%%::;" << "\n";
        shruberryFile << "                        %@@@%(o);  . '         " << "\n";
        shruberryFile << "                        %@@@o%;:(.,'         " << "\n";
        shruberryFile << "                    `.. %@@@o%::;         " << "\n";
        shruberryFile << "                       `)@@@o%::;         " << "\n";
        shruberryFile << "                        %@@(o)::;        " << "\n";
        shruberryFile << "                       .%@@@@%::;         " << "\n";
        shruberryFile << "                       ;%@@@@%::;.          " << "\n";
        shruberryFile << "                      ;%@@@@%%:;;;. " << "\n";
        shruberryFile << "                  ...;%@@@@@%%:;;;;,..    Made By " << executor.getName()  << " for " << target << "\n";
		shruberryFile.close();
        return 0;
	}
	else
    {
		std::cout << RED << " * Error : " << RESET << "can not open file" << std::endl;
        return 1;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << " * ShrubberyCreationForm " << RESET << "destructor called !" << std::endl;
}
