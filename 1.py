# Solucao letra b
class NonExistentEmployee(Exception):
    pass


# Solucao letra d
class NegativeSalary(Exception):
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary


class Staff:
    payroll = {}

    def getSalary(self, name):
        if self.payroll.has_key(name):
            return self.payroll[name]
        else:
            # Solucao letra c
            raise NonExistentEmployee()

    def checkSalary(self, name, salary):
        if salary < 0:
            raise NegativeSalary(name, salary)

    def addEmp(self, name, salary):
        # Solucao letra e
        self.checkSalary(name, salary)
        self.payroll[name] = salary

    def raiseSalary(self, name, salary):
        # Solucao letra f
        currentSalary = self.getSalary(name)  # Valida se o empregado existe
        self.checkSalary(name, salary)  # Valida se o aumento e negativo
        self.payroll[name] = currentSalary + salary

# Solucao letra g
def readEmployees(s):
    name = raw_input("Please, enter a name (Press RETURN to finish) ")
    while name != '':
        salary = float(raw_input("Please, enter the salary: "))
        try:
            s.raiseSalary(name, salary)
        except NonExistentEmployee:
            print("Failed: The employee does not exist.")
        except NegativeSalary:
            print("Failed: The salary cannot be negative.")
        name = raw_input("Please, enter a name (Press RETURN to finish) ")
