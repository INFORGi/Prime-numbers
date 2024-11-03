# Имя исполняемого файла
TARGET = main

# Исходный фалй
SRCS = main.cpp

# Объектынй файл
OBJS = $(SRCS: .cpp = .o)

# Компелятор
CXXFLAGS = -Wall -std=c++11

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
		   $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для компеляции .cpp файлов в .o файлы
%.0: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки проекта 
clean:
	rm -f $(OBJS) $(TARGET)

# Правило для пересоздания проекта
rebuild: clean all