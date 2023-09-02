# This line defines a variable called `SOURCES` that contains the path to the main source file.
set(SOURCES ./main.cpp)

# This line registers the component with the ESP-IDF build system.
# The source files for the component are specified by the `SRCS` variable.
# The include directories for the component are ".".
idf_component_register(
  SRCS ${SOURCES}
  INCLUDE_DIRS .
  REQUIRES component # components that you want to include in your app
)
