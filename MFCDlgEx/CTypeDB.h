// CTypeDB.h
#pragma once

#include <afx.h>
#include <afxtempl.h>   // CArray

// CSV 한 줄에 해당하는 글자 정보 구조체
struct SCharInfo
{
    CString m_char;   // 한글 코드 (예: 가, 나)

    int m_sheet;      // 장 번호
    int m_type;       // 타입 번호

    int m_sx;         // 이미지 상의 x
    int m_sy;         // 이미지 상의 y
    int m_line;       // 줄 번호
    int m_order;      // 줄 안에서의 순서
    int m_width;      // 박스 폭
    int m_height;     // 박스 높이
};

// 글자 DB 클래스
class CTypeDB
{
public:
    CTypeDB();
    ~CTypeDB();

    // 모든 데이터 초기화
    void Clear();

    // CSV 파일 읽어서 m_chars, m_nSheet, m_nChar 채우기
    BOOL ReadCSVFile(const CString& filename);

    // 특정 장에 해당하는 m_chars 인덱스 목록 얻기
    void GetCharsOfSheet(int sheet, CArray<int, int>& indices);

public:
    CArray<SCharInfo, SCharInfo&> m_chars;  // 전체 글자 정보
    int m_nSheet;                           // 전체 장 수
    int m_nChar;                            // 전체 글자 수
};
