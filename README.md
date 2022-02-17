# Ai코코캠(Ai COCOCAM)

코코캠은 AI 비전 센서 기능을 통해 다양한 AI프로젝트를 제작하는데 활용할 수 있고, 온라인 교육 및 화상회의용 웹캠으로도 사용하실 수 있습니다.

코코캠은 얼굴 인식, 마스크 인식, 사물 인식, 사물 추적, 컬러인식, 라인 추적, 모델 학습, 태그 인식, 숫자 인식 기능을 사용할 수 있습니다.

Ai COCOCAM can be used to create various AI projects through the AI Vision Sensor function, and can also be used as a webcam for online education and video conferencing.
Ai COCOCAM can use face recognition, mask recognition, object recognition, object tracking, color recognition, line tracking, model learning, tag recognition, and number recognition functions.


## ~ hint
아래 링크를 통해 코코캠에 대한 자세한 정보를 볼 수 있습니다.

You can find more information about cococam through the link below.

→ [Ai코코캠 제품 살펴보기](https://kocoafab.cc/product/aicococam)

## ~

## 기본 사용법(Basic usage)

```blocks
    Aicococam.initI2c()
    Aicococam.initMode(protocolAlgorithm.ALGORITHM_FACE_RECOGNITION)
```

* 코코캠은 ``||I2C통신||`` 을 사용해 Makecode와 통신합니다.
* Ai COCOCAM communicates with Makecode using ``||I2C Communication||``
　
 

* ``||모드 설정||`` 을 통해 코코캠의 모드를 블록으로 변경할 수 있습니다.
* You can change the mode of the Ai COCOCAM using block on makecode



```blocks
    serial.redirectToUSB()
    Aicococam.initI2c()
    Aicococam.initMode(protocolAlgorithm.ALGORITHM_FACE_RECOGNITION)
```
* 코코캠은 ``||시리얼통신||`` 을 사용해 컴퓨터에 결과를 전달할 수 있습니다.
* Ai COCOCAM can use ``||Serial Communication||`` to deliver results to the computer.


```blocks
    basic.forever(function () {
        Aicococam.request()
        if (Aicococam.isLearned(1)) {
            serial.writeString("1")
        } else {
            serial.writeString("2")
        }
    })
```
* ID1이 검출되면 컴퓨터로 "1"을 전달하고 검출되지 않았다면 "2"를 전달합니다.
* If ID1 is detected, deliver "1" to the computer and "2" if not detected.


## 지원제품(Supported targets)

* for PXT/microbit

## 라이선스(License)

MIT

## 제품 문의(product Inquiries) 

제품에 관한 문의는 ``||02-3470-2829||`` 또는 [minierz@kocoa.or.kr](mailto:minierz@kocoa.or.kr)를 통해 문의 부탁드립니다.

For product inquiries, please contact ``||02-3470-2829||`` or [minierz@kocoa.or.kr](mailto:minierz@kocoa.or.kr).
　

코코아팹 공식 스토어 바로가기 → [코코아팹 스마트 스토어](https://smartstore.naver.com/kocoafab)

Go to the official store of kocoafab
