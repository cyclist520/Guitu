//
//  CXMLElement.h
//  TouchCode
//
//  Created by Jonathan Wight on 03/07/08.
//  Copyright 2011 toxicsoftware.com. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//     1. Redistributions of source code must retain the above copyright notice, this list of
//        conditions and the following disclaimer.
//
//     2. Redistributions in binary form must reproduce the above copyright notice, this list
//        of conditions and the following disclaimer in the documentation and/or other materials
//        provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY TOXICSOFTWARE.COM ``AS IS'' AND ANY EXPRESS OR IMPLIED
//  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TOXICSOFTWARE.COM OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  The views and conclusions contained in the software and documentation are those of the
//  authors and should not be interpreted as representing official policies, either expressed
//  or implied, of toxicsoftware.com.

#import "CXMLNode.h"


// 将XML中tag的内容提取出来
// x表示Element本身, y表示tag的名字, z表示提取出来值保存的位置
#define setupValueForTagName(x, y, z) if ([(x) tagNameEquals:(y)]) \
                                      {\
                                          (z) = [(x) contentsText];\
                                      }

// NSXMLElement
@interface CXMLElement : CXMLNode {

}

- (NSArray *)elementsForName:(NSString *)name;
- (NSArray *)elementsForLocalName:(NSString *)localName URI:(NSString *)URI;

- (NSArray *)attributes;

// 扩展方法
- (NSArray *)childElements;
- (CXMLElement *)childAtIndex:(NSUInteger)index;
- (CXMLElement *)firstChild;
- (NSString *)tagName;
- (BOOL)tagNameEquals:(NSString *)anotherTagName;
- (NSString *)contentsText;
- (NSString *)attribute:(NSString *)name;

- (CXMLNode *)attributeForName:(NSString *)name;
- (CXMLNode *)attributeForLocalName:(NSString *)localName URI:(NSString *)URI;

- (NSArray *)namespaces;
- (CXMLNode *)namespaceForPrefix:(NSString *)name;
- (CXMLNode *)resolveNamespaceForName:(NSString *)name;
- (NSString *)resolvePrefixForNamespaceURI:(NSString *)namespaceURI;

//- (NSString*)_XMLStringWithOptions:(NSUInteger)options appendingToString:(NSMutableString*)str;
@end
