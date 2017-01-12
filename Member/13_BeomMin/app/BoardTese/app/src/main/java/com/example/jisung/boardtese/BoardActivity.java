package com.example.jisung.boardtese;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutCompat;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class BoardActivity extends AppCompatActivity {

    private ListView noticeListView;
    private NoticeListAdapter adapter;
    private List<Notice> noticeList;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_board);

        noticeListView = (ListView)findViewById(R.id.noticeListView);
        noticeList = new ArrayList<Notice>();
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        noticeList.add(new Notice("공지사항입니다","정지성입니다","2017-01-11"));
        adapter = new NoticeListAdapter(getApplicationContext(),noticeList);
        noticeListView.setAdapter(adapter);
        final Button courseButton =(Button) findViewById(R.id.courseButton);
        final Button statisticsButton =(Button) findViewById(R.id.statsticsButton);
        final Button scheduleButton =(Button) findViewById(R.id.scheduleButton);
        final LinearLayout notice=  (LinearLayout) findViewById(R.id.notice);

        courseButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                notice.setVisibility(View.GONE);
                courseButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                statisticsButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                scheduleButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                FragmentManager fragmentManager = getSupportFragmentManager();
                FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
                fragmentTransaction.replace(R.id.fragment,new CourseFragment());
                fragmentTransaction.commit();
            }
        });
        statisticsButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                notice.setVisibility(View.GONE);
                courseButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                statisticsButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                scheduleButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                FragmentManager fragmentManager = getSupportFragmentManager();
                FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
                fragmentTransaction.replace(R.id.fragment,new StatsticsFragment());
                fragmentTransaction.commit();
            }
        });
        scheduleButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                notice.setVisibility(View.GONE);
                courseButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                statisticsButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                scheduleButton.setBackgroundColor(getResources().getColor(R.color.colorPrimaryDark));
                FragmentManager fragmentManager = getSupportFragmentManager();
                FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
                fragmentTransaction.replace(R.id.fragment,new ScheduleFragment());
                fragmentTransaction.commit();
            }
        });
    }
}
