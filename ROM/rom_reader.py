with open("rom.bin","rb") as f:
     #read 1 byte
     while (byte := f.read(1)):
          # Process the byte (e.g., get its integer value)
          byte_value = byte[0]
          if(byte_value == 1):
               print("LOAD",end=' ')
               operand = f.read(1)
               print(operand[0])
          elif(byte_value == 2):
               print("MOVE")
          elif(byte_value == 3):
               print("ADD")
          elif(byte_value== 4):
               print("HALT")

f.close()