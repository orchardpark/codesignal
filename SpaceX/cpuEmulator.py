def parse_register(registerName)->int:
    return int(registerName[1:])

def solution(subroutine):
    registers = [0]*43
    modulus = 2**32
    idx = 0
    while idx<len(subroutine):
        call = subroutine[idx]
        tokens = call.split(' ')
        instruction = tokens[0]
        if instruction == "MOV":
            args = tokens[1].split(',')
            if args[0].startswith('R'):
                first = parse_register(args[0])
                second = parse_register(args[1])
                registers[second] = registers[first]
            else:
                second = parse_register(args[1])
                registers[second] = int(args[0])
        elif instruction == "ADD":
            args = tokens[1].split(',')
            first = parse_register(args[0])
            second = parse_register(args[1])
            registers[first] = (registers[first]+registers[second]) % modulus
        elif instruction == "INC":
            first = parse_register(tokens[1])
            count = registers[first]+1
            if(count >= modulus):
                count = 0
            registers[first] = count
        elif instruction == "DEC":
            first = parse_register(tokens[1])
            count = registers[first]-1
            if(count < 0):
                count = modulus-1
            registers[first]=count
        elif instruction == "INV":
            first = parse_register(tokens[1])
            count = registers[first]
            registers[first] = count ^ (modulus-1)
        elif instruction == "JMP":
            idx = int(tokens[1])-1
            continue
        elif instruction == "JZ":
            if(registers[0]==0):
                idx = int(tokens[1])-1
                continue
        idx+=1
            
    return str(registers[42])
