# Sprint 1: Video Streaming Client MVP Start

## Sprint goal

서버 스트림 수신 클라이언트의 MVP 기반을 시작한다. 이번 스프린트는 실제 영상 표시 전체 완성보다, 연결 설정부터 수신 루프와 화면 표시 구조까지 이어지는 최소 동작 흐름을 구현 가능한 작업 단위로 확정하고 첫 개발 착수 상태로 만든다.

## Sprint period

- Start: 2026-07-02
- Type: Daily sprint
- Source backlog: `product_backlogs.md`

## Selected product backlog items

| Backlog ID | Title | Priority | Sprint Decision |
| --- | --- | --- | --- |
| PB-003 | 연결 설정 | P0 | Included |
| PB-004 | 스트림 연결 | P0 | Included |
| PB-005 | 스트림 수신 | P0 | Included |
| PB-006 | 영상 디코딩 | P0 | Included |
| PB-007 | 화면 표시 | P0 | Included |
| PB-008 | 연결 해제 | P0 | Included |
| PB-009 | 애플리케이션 종료 | P0 | Included |

## Planned tasks

| Task ID | Owner | Task | Related Backlog | Status | Acceptance Criteria |
| --- | --- | --- | --- | --- | --- |
| S1-T001 | ScrumMaster | Sprint 1 목표, 범위, 작업 순서 확정 | PB-003~PB-009 | Done | 스프린트 목표와 작업 순서가 문서화된다. |
| S1-T002 | Developer | 클라이언트 실행 파일 이름과 기본 구조 결정 | PB-003 | Ready | 기존 `smoke_test`에서 실제 클라이언트 타겟으로 전환할 계획이 명확하다. |
| S1-T003 | Developer | 서버 URL 설정 모델 정의 | PB-003 | Ready | 기본 URL, 프로토콜, 호스트, 포트 입력 또는 설정 구조가 정해진다. |
| S1-T004 | Developer | 스트림 연결 인터페이스 작성 | PB-004 | Ready | connect 실패와 성공 결과를 구분하는 API가 있다. UI 또는 콘솔에서 연결 상태를 확인할 수 있다. |
| S1-T005 | Developer | 비동기 수신 루프 설계 및 구현 | PB-005 | Ready | 수신 처리가 UI 또는 메인 흐름을 막지 않는다. 종료 요청을 안전하게 처리한다. |
| S1-T006 | Developer | 수신 프레임 디코딩 경로 작성 | PB-006 | Ready | OpenCV 기반 디코딩 경로가 준비된다. 실패 프레임은 애플리케이션 종료 없이 처리된다. |
| S1-T007 | Developer | 최신 프레임 화면 표시 구조 작성 | PB-007 | Ready | 최신 프레임이 화면 갱신 대상으로 전달된다. 창 크기 변경 시 표시 정책이 정해진다. |
| S1-T008 | Developer | Disconnect 및 종료 정리 로직 작성 | PB-008, PB-009 | Ready | 연결, 수신 루프, 리소스가 명시적으로 정리된다. 반복 실행 시 충돌이 없어야 한다. |
| S1-T009 | Reviewer | Sprint 1 구현 결과 품질 검토 | PB-003~PB-009 | Pending | 빌드, 실행, 종료, 오류 처리 경로를 검토한다. 수정 필요 사항을 기록한다. |

## Task order

1. S1-T002: 실행 타겟과 앱 구조 결정
2. S1-T003: 서버 URL 설정 모델 정의
3. S1-T004: 연결 인터페이스 작성
4. S1-T005: 수신 루프 작성
5. S1-T006: 디코딩 경로 작성
6. S1-T007: 화면 표시 구조 작성
7. S1-T008: 연결 해제와 종료 정리 작성
8. S1-T009: 리뷰 및 품질 게이트

## Blockers

| ID | Blocker | Impact | Owner | Status | Decision |
| --- | --- | --- | --- | --- | --- |
| B1 | 서버 스트리밍 프로토콜이 아직 확정되지 않음 | 연결/수신 구현 범위가 달라질 수 있음 | Product Owner | Open | Sprint 1은 RTSP 또는 OpenCV `VideoCapture`로 시작 가능한 구조를 우선 가정한다. |
| B2 | 샘플 스트림 URL이 아직 없음 | 통합 테스트가 제한됨 | Product Owner | Open | 로컬 테스트 영상 또는 샘플 URL 확보 전까지 빌드와 구조 테스트를 우선 수행한다. |
| B3 | Qt UI 방식이 확정되지 않음 | 화면 표시 구현 방식이 달라질 수 있음 | Product Owner, Developer | Open | 현재 프로젝트의 Qt Core 기반을 고려해 최소 변경 후 UI 선택을 확정한다. |

## Current status

- Sprint status: Started
- Planning status: Done
- Implementation status: Ready for Developer
- Review status: Pending
- Main risk: 프로토콜과 샘플 스트림이 확정되지 않아 실제 수신 검증은 제한될 수 있다.

## Definition of Done

- 선택된 P0 백로그 항목의 Acceptance Criteria가 코드 또는 명확한 구현 준비 상태로 충족된다.
- CMake 빌드가 성공한다.
- 실행 중 UI 또는 메인 흐름이 멈추지 않는다.
- 연결 실패, 디코딩 실패, 종료 경로가 애플리케이션 비정상 종료 없이 처리된다.
- Reviewer가 Sprint 1 결과를 검토하고 승인 또는 수정 요청을 기록한다.

## Developer handoff

Developer는 S1-T002부터 시작한다. 첫 구현 목표는 전체 기능을 한 번에 완성하는 것이 아니라, 스트리밍 클라이언트가 확장 가능한 형태로 연결 설정, 연결 시도, 수신 루프, 종료 정리 흐름을 갖추는 것이다.

권장 첫 번째 구현 범위:

- `CMakeLists.txt`에 실제 클라이언트 타겟명 정리
- `src/main.cpp`를 스트리밍 클라이언트 진입점으로 전환
- 서버 URL 기본값을 코드 또는 설정으로 주입
- OpenCV `VideoCapture` 기반의 최소 연결 시도 구현
- 종료 시 캡처 리소스 정리

## Reviewer handoff

Reviewer는 Developer 구현 이후 다음 항목을 우선 확인한다.

- 빌드 성공 여부
- Run/Debug 실행 가능 여부
- 연결 실패 시 안전한 오류 처리
- 스트리밍 루프가 종료 가능한 구조인지 여부
- 향후 Qt UI 도입 시 구조적 변경이 과도하지 않은지 여부

## Next action

Developer가 S1-T002를 착수한다. 프로토콜과 샘플 URL이 확정되기 전까지는 OpenCV `VideoCapture` 기반 최소 스트림 연결 흐름을 구현 기준으로 삼는다.
