import glob
import logging
import os 


Test_Files = ["/home/webtech/pbn/test/equipos.txt",
              "/home/webtech/pbn/test/equipos_corto.txt",
              "/home/webtech/pbn/test/equipos_mediano.txt",
              "/home/webtech/pbn/test/a.txt"]
# specify the directory and file extension
directory = '/home/webtech/pbn/test'
extension = '*.txt'

# use glob to get all files with the specified extension
file_list = glob.glob(directory + '/' + extension)

# print the list of files

#Todo: Revisar que exista un nuevo elemento en la lista
if len(Test_Files) != len(file_list):
    print("The file generated an output")
    file_path = list(set(file_list) - set(Test_Files))[0]
    file = open(file_path,"r")
    line_counter = 0
    matches = []
    for line in file:
            
        lines_set = (line.strip().split(","))
        try:

            i = lines_set.index('')
            lines_set.pop(i)
        except:
            pass
        finally:
            
            lines_set = set(lines_set)

        if len(lines_set) != 5:
            print("Se cayo en la geneneracion de partidos!")
            print(lines_set)
            exit()

        matches.append(lines_set)
        line_counter += 1
    
        
    if line_counter in [20,50,500,] and len(matches) in [20,50,500]:
        print("Tiene un 4 gente")
        print(line_counter)
    else:
        print("Si no corriste con archivo de test, quedo la caga am sorry")
        print(line_counter)


    file.close()
else:
    print("Se cayo en la generacion de un archivo")

# os.system("time ./Testing")


#Todo: Leer el archivo y calcular la cantidad de lineas que deberia tener