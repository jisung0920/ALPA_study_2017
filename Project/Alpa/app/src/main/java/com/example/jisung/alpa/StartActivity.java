package com.example.jisung.alpa;


import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;


public class StartActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        mHandler.postDelayed(new Runnable() { //* 핸들러의 postDelayed 사용
            @Override
            public void run() {
                doUpload();
            }
        },10);

    }

    Handler mHandler = new Handler() {
        public void handleMessage(Message msg) {
            if (msg.what == 0) {
                doUpload();
            }
        }
    };

    void doUpload() {
        // 약 2초의 지연시간뒤에 (20 * 100ms) 업로드 완료 toast 출력
        for (int i = 0; i < 20; i++) {
            try { Thread.sleep(100); } catch (InterruptedException e) {;}
        }
        Intent registerIntent = new Intent(StartActivity.this, LoginActivity.class);
        StartActivity.this.startActivity(registerIntent);
    }
}



