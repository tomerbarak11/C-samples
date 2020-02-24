/*test number 1*/

	ASSERT_EQUAL_INT(ListInsertHead(NULL,&p1),&p1);
	ASSERT_THAT(p1.m_next==NULL);

/*test number 2*/
	ASSERT_EQUAL_INT(ListInsertHead(&p2,&p1),&p1);
	ASSERT_THAT(p2.m_next==NULL);
