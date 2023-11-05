# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)


# set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/examples/common_components/protocol_examples_common"
# 					     "${CMAKE_CURRENT_LIST_DIR}/../../libraries/coreMQTT"
# 					     "${CMAKE_CURRENT_LIST_DIR}/../../libraries/coreJSON"
# 						 "${CMAKE_CURRENT_LIST_DIR}/../../libraries/Jobs-for-AWS-IoT-embedded-sdk"
# 						 "${CMAKE_CURRENT_LIST_DIR}/../../libraries/backoffAlgorithm"
# 						 "${CMAKE_CURRENT_LIST_DIR}/../../libraries/common/posix_compat"
# 	)

set(EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/examples/common_components/protocol_examples_common"
						 "esp-aws-iot/libraries/coreMQTT"
						 "esp-aws-iot/libraries/Jobs-for-AWS-IoT-embedded-sdk"
						 "esp-aws-iot/libraries/coreJSON"
						 "esp-aws-iot/libraries/backoffAlgorithm"
						 "esp-aws-iot/libraries/common/posix_compat"
)
# 	"esp-aws-iot/libraries/backoffAlgorithm"
# 	"esp-aws-iot/libraries/coreMQTT"
# 	"esp-aws-iot/libraries/common/posix_compat"
# 	)
project(esp32-iot-application)
