import random

def evaluateFormula(F, m1, m2):
    
    len1 = len(m1)
    for clause in F:        
        len2 = len(clause)
        count = 0
        for i in range(len1):
            if m1[i] in clause:
                count += 1
        
        if count == len2:
            for i in range(count):
                if m2[i] != clause.get(m1[i]):
                    return False

    return True

def getUnitLiteral(F, m1, m2):
    
    unit_literal = dict()
    
    for clause in F:
        len1 = len(m1)
        temp = [key for key in clause.keys()]
        for i in range(len1):
            if m1[i] in clause:
                temp.remove(m1[i])
        
        if len(temp) == 1:
            for literal in temp:
                if literal not in unit_literal.keys():
                    unit_literal[literal] = clause.get(literal)
                    
    return unit_literal
            
def getUnassignedLiterals(F, m1):
    literals = []
    for clause in F:
        for literal in clause.keys():
            if literal not in literals and literal not in m1:
                literals.append(literal)
    return literals

def getLiterals(F):
    literals = []
    for clause in F:
        for literal in clause.keys():
            if literal not in literals:
                literals.append(literal)
    return literals

def DPLL(F, m1, m2):
   
    if len(m1) != 0:
        print('h1')
        if evaluateFormula(F, m1, m2):
            pass
        else:
            m1.pop()
            m2.pop()
            print('poping h1')
            print(m1, m2)
            return False, m1, m2
    

    temp = getUnassignedLiterals(F, m1)
    
    while len(temp) != 0:
        unit_literal = getUnitLiteral(F, m1, m2)
    
        if len(unit_literal.keys()) != 0 and len(m1) != 0:
            print('h2')
            for literal in unit_literal.keys():            
                m1.append(literal)
                m2.append(unit_literal.get(literal))
                #print(m1)
                #print(m2)
                print('assign',literal, unit_literal.get(literal), 'h2')
                print(m1, m2)
                return DPLL(F, m1, m2)
        
        print('h3')
        flag = False
        r = random.randint(0, len(temp)-1)
        literal = temp[r]
        b = random.choice([True, False])
        if b:
            
            m1.append(literal)
            m2.append(b)
            print('assign',literal, b, 'h3')
            print(m1, m2)
            flag, m1, m2 = DPLL(F, m1, m2)
            if flag == True:
                pass
            else:
                m1.append(literal)
                m2.append(False)
                print('assign',literal, False, 'h3')
                print(m1, m2)
                return DPLL(F, m1, m2)
        else:
            
            m1.append(literal)
            m2.append(b)
            print('assign',literal, b, 'h3')
            print(m1, m2)
            flag, m1, m2 = DPLL(F, m1, m2)
            if flag == True:
                pass
            else:
                m1.append(literal)
                m2.append(True)
                print('assign',literal, True, 'h3')
                print(m1, m2)
                return DPLL(F, m1, m2)
        temp = getUnassignedLiterals(F, m1);
    
    if flag == True:
        return True, m1, m2
    return False, None, None
    

formula = [{'A4' : True, 'A5' : False}, {'A5' : True, 'A1' : True, 'A2' : True}, {'A3' : True }]

assign1 = []
assign2 = []

print(getUnitLiteral(formula, ['A1','A5'], [True, False]))

print(DPLL(formula, assign1, assign2))

#DPLL(formula, assign1, assign2)