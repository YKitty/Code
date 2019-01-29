CURR_PATH=$(shell cd ..;pwd) #当前目录，采用命令代换

cc=gcc

#obj=$(shell ls $(CURR_PATH)/*.c | sed -e 's/\.c/\.o/')

%.o:$(CURR_PATH)/%.c
	$(cc) -c $< -o  

