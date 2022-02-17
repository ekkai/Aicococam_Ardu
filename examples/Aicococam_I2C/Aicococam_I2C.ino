#include <COCOCAM.h>
#include <SoftwareSerial.h>

COCOCAM cococam;

void printResult(cococamResult result);
cococamResult result;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  while (!cococam.begin(Wire))
  {
    Serial.println(F("연결 실패!"));
    Serial.println(F("1. AIcococam 의 프로토콜을 확인해주세요. (환경 설정 >> 통신 설정 >> I2C)"));
    Serial.println(F("2. 다시 재연결해주세요."));
    delay(100);
  }

  // 코코캠 알고리즘 설정
  cococam.writeAlgorithm(ALGORITHM_FACE_RECOGNITION);
  
  /*    ALGORITHM_FACE_RECOGNITION,
    ALGORITHM_OBJECT_TRACKING,
    ALGORITHM_OBJECT_RECOGNITION,
    ALGORITHM_LINE_TRACKING,
    ALGORITHM_COLOR_RECOGNITION,
    ALGORITHM_TAG_RECOGNITION,
    ALGORITHM_OBJECT_CLASSIFICATION,
    ALGORITHM_MASK_RECOGNITION,
    ALGORITHM_DIGIT_RECOGNITION
  */
}

void loop() {
  Serial.println("=====");
  cococam.request();

  // 인식 결과 출력
  while (cococam.available()) {
    result = cococam.read();
    printResult(result);
  }
}


void printResult(cococamResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) { //result is a block
    Serial.println(String() + F("Block:xCenter=") + result.xCenter + F(",yCenter=") + result.yCenter + F(",width=") + result.width + F(",height=") + result.height + F(",ID=") + result.ID);
  }
  else if (result.command == COMMAND_RETURN_ARROW) { //result is an arrow
    Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(",yOrigin=") + result.yOrigin + F(",xTarget=") + result.xTarget + F(",yTarget=") + result.yTarget + F(",ID=") + result.ID);
  }
  else { //result is unknown.
    Serial.println("Object unknown!");
  }
}
